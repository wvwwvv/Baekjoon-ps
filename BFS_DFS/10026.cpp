#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <tuple>
#define FIO ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0)
#define X first
#define Y second
using namespace std;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int N;
string board[101];
bool vis[101][101];

int func() {

	cin >> N;
	
	for (int i = 0; i < N; i++) cin >> board[i];

	queue<pair<int, int>> Q1; //일반인
	queue<pair<int, int>> Q2; //적록색약

	int ans1 = 0; //일반인
	int ans2 = 0; //적록색약

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {

			if (vis[i][j]) continue;

			char temp = board[i][j];
			Q1.push({ i,j });
			vis[i][j] = true;
			ans1++;

			while (!Q1.empty()) {  //일반인 BFS 시작
				auto cur = Q1.front(); Q1.pop();

				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];

					if (nx < 0 || nx >= N || ny < 0 || ny >= N)continue;
					if (board[nx][ny] != temp) continue;
					if (vis[nx][ny]) continue;

					vis[nx][ny] = true;
					Q1.push({ nx,ny });
				}
			}
		}
	}

	for (int i = 0; i < 101; i++)
		for (int j = 0; j < 101; j++)
			vis[i][j] = false;


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {

			if (vis[i][j]) continue;

			char temp = board[i][j];
			Q2.push({ i,j });
			vis[i][j] = true;
			ans2++;

			while (!Q2.empty()) {  //일반인 BFS 시작
				auto cur = Q2.front(); Q2.pop();

				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];

					if (nx < 0 || nx >= N || ny < 0 || ny >= N)continue;

					if (temp == 'B') { 
						if (board[nx][ny] != temp) continue;
					}
					else {
						if (board[nx][ny] == 'B') continue;
					}
					if (vis[nx][ny]) continue;

					vis[nx][ny] = true;
					Q2.push({ nx,ny });
				}
			}
		}
	}


	cout << ans1 << ' ' << ans2;
	return 0;
}


int main() {
	
	FIO;

	func();

	
	return 0;
}