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
int board[101][101];
bool vis[101][101];
int afterRain[101][101]; // 0 : 안잠김  1 : 잠김
int ans = 0;

int func() {

	cin >> N;

	int trial = 0; //가장 높은곳

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			trial = max(trial, board[i][j]);
		}

	

	while (trial--) { // trial 이하의 높이는 물에 잠김
		for (int i = 0; i < 101; i++) //매 trial마다 초기화
			for (int j = 0; j < 101; j++) {
				afterRain[i][j] = 0;
				vis[i][j] = false;
			}


		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++) {
				if (board[i][j] <= trial) {
					afterRain[i][j] = 1;
				}
			}

		queue<pair<int, int>> Q;
		int num = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (afterRain[i][j] == 1 || vis[i][j]) continue; //잠겼거나 방문했으면

				Q.push({ i,j });
				vis[i][j] = true;
				num++;

				while (!Q.empty()) {
					auto cur = Q.front(); Q.pop();

					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];

						if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
						if (afterRain[nx][ny] == 1 || vis[nx][ny]) continue;
						Q.push({ nx,ny });
						vis[nx][ny] = true;
					}
				}
				ans = max(ans, num);
			}
		}
	}

	cout << ans;
	

	return 0;
}


int main() {
	
	FIO;

	func();

	
	return 0;
}