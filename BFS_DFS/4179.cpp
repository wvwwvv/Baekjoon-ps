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

int R, C; // 행, 열 <=1000
string board[1001];
int dist_J[1001][1001];
int dist_F[1001][1001];

int main() {
	FIO;

	cin >> R >> C;

	queue<pair<int, int>> J;
	queue<pair<int, int>> F;

	for (int i = 0; i < R; i++) cin >> board[i];

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			dist_J[i][j] = -1;
			dist_F[i][j] = -1;
		}
	}

	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++) {
			if (board[i][j] == 'J') {
				J.push({ i,j });
				dist_J[i][j] = 0;
			}

			if (board[i][j] == 'F') {
				F.push({ i,j });
				dist_F[i][j] = 0;
			}

		}

	while (!F.empty()) { //F에 대한 BFS 먼저 시행
		auto cur = F.front(); F.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
			if (board[nx][ny] == '#') continue;
			if (dist_F[nx][ny] >= 0) continue;
			dist_F[nx][ny] = dist_F[cur.X][cur.Y] + 1;
			F.push({ nx,ny });
		}
	}

	while (!J.empty()) { //J에 대한 BFS 시행
		auto cur = J.front(); J.pop();

		if (cur.X == 0 || cur.X == R - 1 || cur.Y == 0 || cur.Y == C - 1) { //시작부터 J의 위치가 가장자리일 경우
			cout << 1;
			return 0;
		}

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
			if (board[nx][ny] == '#') continue;
			if (dist_J[nx][ny] >= 0) continue;

			dist_J[nx][ny] = dist_J[cur.X][cur.Y] + 1;

			if (dist_J[nx][ny] >= dist_F[nx][ny]) { //불에 따라잡힘
				if (dist_F[nx][ny] != -1) continue;
			}

			if (nx == 0 || ny == 0 || nx == R - 1 || ny == C - 1) { // 가장자리에 있으면,
				cout << dist_J[nx][ny] + 1;
				return 0;
			}

			J.push({ nx,ny });
		}
	}

	cout << "IMPOSSIBLE";
	return 0;
}