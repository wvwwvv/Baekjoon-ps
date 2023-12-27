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
string board[26];
bool vis[26][26];


int func() {

	cin >> N;

	for (int i = 0; i < N; i++) cin >> board[i];
	
	queue<pair<int, int>> Q;

	int num = 0; //단지 수
	vector<int> area; //각 단지의 집 수
		
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] == '0' || vis[i][j]) continue;
			
			Q.push({ i,j });
			vis[i][j] = true;
			num++;

			int cnt = 0;

			while (!Q.empty()) {
				cnt++;
				auto cur = Q.front(); Q.pop();

				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];
					if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
					if (board[nx][ny] == '0' || vis[nx][ny]) continue;
					Q.push({ nx,ny });
					vis[nx][ny] = true;
				}
			}
			area.push_back(cnt);
		}
	}

	sort(area.begin(), area.end());

	cout << num << '\n';

	for (auto ans : area) cout << ans << '\n';




	return 0;
}


int main() {
	
	FIO;

	func();

	
	return 0;
}