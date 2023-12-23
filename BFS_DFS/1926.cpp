#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <tuple>
#define FIO ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0)
#define X first
#define Y second
using namespace std;

int n, m;
int board[501][501];
bool vis[501][501];
int num = 0;
int mx = 0;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int main() {

	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];


	queue<pair<int, int>> Q;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 0 || vis[i][j]) continue;

			Q.push({ i,j });
			vis[i][j] = 1;
			num++;
			int area = 0;

			while (!Q.empty()) {
				auto cur = Q.front(); Q.pop();
				area++;

				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];

					if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
					if (board[nx][ny] == 0 || vis[nx][ny]) continue;
					vis[nx][ny] = 1;
					Q.push({ nx,ny });
				}
			}

			mx = max(mx, area);

		}
	}

	cout << num << '\n' << mx;

	return 0;
}