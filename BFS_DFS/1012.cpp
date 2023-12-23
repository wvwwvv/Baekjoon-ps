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
int N, M; // 행과 열 <=50
int K; //배추의 개수

int board[51][51];
bool vis[51][51];

int func() {

	cin >> T;

	while (T--) { //test case 시작

		cin >> M >> N >> K; //열과 행 순서로 받음

		for (int i = 0; i < 51; i++) {
			for (int j = 0; j < 51; j++) {
				board[i][j] = 0;
				vis[i][j] = false;
			}
		}

		for (int i = 0; i < K; i++) {
			int x, y;
			cin >> x >> y;
			board[y][x] = 1; //문제에서 주어진게 x는 가로, y는 세로이고, 이때 x는 열, y는 행이다.
		}

		queue<pair<int, int>> Q;
		int num = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (board[i][j] == 0 || vis[i][j]) continue;

				Q.push({ i,j }); //하나의 영역 시작
				num++;
				vis[i][j] = true;

				while (!Q.empty()) {
					auto cur = Q.front(); Q.pop();

					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];
						if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
						if (board[nx][ny] == 0 || vis[nx][ny]) continue;
						vis[nx][ny] = true;
						Q.push({ nx,ny });
					}
				}
			}
		}

		cout << num << '\n';

	}



	return 0;
}


int main() {
	
	FIO;

	func();

	return 0;
}