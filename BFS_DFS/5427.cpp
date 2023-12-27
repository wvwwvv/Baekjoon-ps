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

int T;
string board[1024];
int dist1[1024][1024];
int dist2[1024][1024];

int func() {

	cin >> T;

	while (T--) {
		for (int i = 0; i < 1024; i++) board[i] = {};
		for (int i = 0; i < 1024; i++)
			for (int j = 0; j < 1024; j++) {
				dist1[i][j] = -1;
				dist2[i][j] = -1;
			}


		int w, h; //열과 행
		cin >> w >> h;

		queue<pair<int, int>> Q1; //상근
		queue<pair<int, int>> Q2; //불

		for (int i = 0; i < h; i++) cin >> board[i];

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (board[i][j] == '@') { //상근
					Q1.push({ i,j });
					dist1[i][j] = 0;
				}

				if (board[i][j] == '*') { //불
					Q2.push({ i,j });
					dist2[i][j] = 0;
				}
			}
		}

		if (Q1.front().X == 0 || Q1.front().X == h-1 || Q1.front().Y == 0 || Q1.front().Y == w-1) { //상근이가 시작부터 가장자리에 있을경우
			cout << 1 <<'\n';
			continue;
		}

		while (!Q2.empty()) { //불 BFS
			auto cur = Q2.front(); Q2.pop();

			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];
				if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
				if (dist2[nx][ny] >= 0 || board[nx][ny] == '#') continue;
				dist2[nx][ny] = dist2[cur.X][cur.Y] + 1;
				Q2.push({ nx,ny });
			}
		}
		
		bool flag1 = false;
		bool flag2 = false;

		while (!Q1.empty()) {
			auto cur = Q1.front(); Q1.pop();

			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];
				if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
				if (dist1[nx][ny] >= 0 || board[nx][ny] == '#') continue;

				dist1[nx][ny] = dist1[cur.X][cur.Y] + 1;

			
				if ((dist1[nx][ny] < dist2[nx][ny]) && (nx == 0 || nx == h - 1 || ny == 0 || ny == w - 1)) { //불을피해 가장자리에 도착했을 경우
					flag1 = true;
					flag2 = true;
					cout << dist1[nx][ny] + 1<<'\n';
					break;
				}
				else if (dist2[nx][ny] == -1 && (nx == 0 || nx == h - 1 || ny == 0 || ny == w - 1)) { //불이 처음부터 없었을 경우
					flag1 = true;
					flag2 = true;
					cout << dist1[nx][ny] + 1<<'\n';
					break;
				}
	
				Q1.push({ nx,ny });
			}

			if (flag1 == true) break;
		}

		if (flag2 == false) {
			cout << "IMPOSSIBLE" << '\n';
		}

	}

	return 0;
}


int main() {
	
	FIO;

	func();

	
	return 0;
}