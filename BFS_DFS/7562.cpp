#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <tuple>
#define FIO ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0)
#define X first
#define Y second
using namespace std;

int dist[301][301];

int dx[8] = { 1,2,2,1,-1,-2,-2,-1 };
int dy[8] = { 2,1,-1,-2,-2,-1,1,2 };


int func() {

	int T;

	cin >> T;

	while (T--) {
		int I;
		int x1, y1, x2, y2;

		cin >> I;
		cin >> x1 >> y1 >> x2 >> y2;

		if (x1 == x2 && y1 == y2) {
			cout << 0 << '\n';
			continue;
		}

		queue<pair<int, int>> Q;

		for (int i = 0; i < 301; i++)
			for (int j = 0; j < 301; j++)
				dist[i][j] = -1;

		Q.push({ x1,y1 });
		dist[x1][y1] = 0;

		while (dist[x2][y2] == -1) {
			auto cur = Q.front(); Q.pop();

			for (int dir = 0; dir < 8; dir++) {
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];

				if (nx < 0 || nx >= I || ny < 0 || ny >= I) continue;
				if (dist[nx][ny] >= 0) continue;

				dist[nx][ny] = dist[cur.X][cur.Y] + 1;
				Q.push({ nx,ny });
			}
		}

		cout << dist[x2][y2] << '\n';

	}
	

	return 0;
}


int main() {
	
	FIO;

	func();

	
	return 0;
}