#include <iostream>
#include <algorithm>
#include <queue>
#define X first
#define Y second
using namespace std;
#define FIO ios::sync_with_stdio(0), cin.tie(0)

string board[5];
int subArr[25];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int ans = 0;


int main() {

	FIO;

	for (int i = 0; i < 5; i++) cin >> board[i];
	for (int i = 0; i < 25; i++) subArr[i] = 1;
	for (int i = 0; i < 7; i++) subArr[i] = 0; // 25C7하기 위해

	do {
		bool is7[5][5] = {}; // 7공주이면 true
		bool vis[5][5] = {};
		int S = 0; //이다솜파의 수
		int adj = 0; //인접한 학생 수
		queue<pair<int, int>> Q;

		for (int i = 0; i < 25; i++) {
			if (subArr[i] == 0) {
				int x = i / 5;
				int y = i % 5;
				is7[x][y] = true;
				if (board[x][y] == 'S') S++;
				if (Q.empty()) {
					Q.push({ x,y }); //모든 7공주가 인접해있는지 판단하기위해 최초 1번 한명의 위치 큐에 넣기
					vis[x][y] = true;
				}
			}
		}

		while (!Q.empty()) { //BFS start
			auto cur = Q.front(); Q.pop();
			adj++; 

			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];

				if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
				if (!is7[nx][ny] || vis[nx][ny]) continue;
				Q.push({ nx,ny });
				vis[nx][ny] = true;
			}
		}

		if (S >= 4) {
			if (adj == 7)
				ans++;
		}

	} while (next_permutation(subArr, subArr + 25));

	cout << ans;

	return 0;
}
