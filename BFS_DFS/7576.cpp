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

int N, M; // <= 1000인 행과 열
int board[1001][1001]; //1:익은 토마토 0: 안익은 토마토 -1: 빈자리
int dist[1001][1001]; //익기 위한 시간



int main() {

	cin >> M >> N;

	queue<pair<int, int>> Q;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			if (board[i][j] == 0) dist[i][j] = -1; //안익은 토마토의 초기 dist값이 -1 이고, 익으면 값 갱신, 모든 시행이 끝난 후 -1이 하나라도 남아있으면 -1출력 후 리턴
			if (board[i][j] == 1) Q.push({ i,j }); //익은 토마토들의 위치 큐에 모두 넣음
		}

	while (!Q.empty()) {
		auto cur = Q.front(); Q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			if (dist[nx][ny] >= 0) continue; //초기에 익은 토마토이거나, 시간이지나 익게 된 토마토
			if (board[nx][ny] == -1) continue;

			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			Q.push({ nx,ny });
		}
	}

	int ans = 0;

	for (int i=0;i<N;i++)
		for (int j = 0; j < M; j++) {
			if (dist[i][j] == -1) {
				cout << -1;
				return 0;
			} 

			ans = max(ans, dist[i][j]);
		}

	
	cout << ans;
	
	return 0;
}