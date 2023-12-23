#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <tuple>
#define FIO ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0)
#define X first
#define Y second
using namespace std;

int N, M;
string board[101];  //2<=N,M<=100
int dist[101][101];

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int ans = 0;

int main() {

	cin >> N >> M;

	for (int i = 0; i < N; i++) cin >> board[i];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			dist[i][j] = -1;

	queue<pair<int, int>> Q;
	dist[0][0] = 1; //dist값이 1 이상이면 방문했음을 의미 + 이동횟수
	Q.push({ 0,0 });

	while (!Q.empty()) {
		auto cur = Q.front(); Q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			if (board[nx][ny] == '0' || dist[nx][ny] >= 1) continue;
			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			Q.push({ nx,ny });
		}
	}

	cout << dist[N - 1][M - 1];

	return 0;
}