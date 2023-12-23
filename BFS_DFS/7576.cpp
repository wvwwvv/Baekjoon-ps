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

int N, M; // <= 1000�� ��� ��
int board[1001][1001]; //1:���� �丶�� 0: ������ �丶�� -1: ���ڸ�
int dist[1001][1001]; //�ͱ� ���� �ð�



int main() {

	cin >> M >> N;

	queue<pair<int, int>> Q;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			if (board[i][j] == 0) dist[i][j] = -1; //������ �丶���� �ʱ� dist���� -1 �̰�, ������ �� ����, ��� ������ ���� �� -1�� �ϳ��� ���������� -1��� �� ����
			if (board[i][j] == 1) Q.push({ i,j }); //���� �丶����� ��ġ ť�� ��� ����
		}

	while (!Q.empty()) {
		auto cur = Q.front(); Q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			if (dist[nx][ny] >= 0) continue; //�ʱ⿡ ���� �丶���̰ų�, �ð������� �Ͱ� �� �丶��
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