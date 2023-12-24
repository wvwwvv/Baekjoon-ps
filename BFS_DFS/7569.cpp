#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <tuple>
#define FIO ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0)
#define X first
#define Y second
using namespace std;

int H, N, M; //���� 1~100 �� 1~200 �� 1~200 
int board[101][201][201]; //����, ��, �� ����			1:���� �丶�� 0: ������ �丶�� -1: ���ڸ�
int dist[101][201][201];

int dx[6] = { 0,1,0,-1,0,0 };
int dy[6] = { 1,0,-1,0,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };

int func() {

	cin >> M >> N >> H; 

	queue<tuple<int, int, int>> Q; // i,j,k ������� �־����Ƿ� ���� <����, ��, ��> == < nz, nx, ny > == <H ,N ,M>

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				cin >> board[i][j][k];
				if (board[i][j][k] == 1) Q.push({ i,j,k });

				if (board[i][j][k] == 0) dist[i][j][k] = -1; //��� ������ ������ dist���� -1�� �ϳ��� ������ -1����ϰ� ����
			}
		}
	}

	while (!Q.empty()) {
		auto cur = Q.front(); Q.pop();

		for (int dir = 0; dir < 6; dir++) {
			int nx = get<1>(cur) + dx[dir];
			int ny = get<2>(cur) + dy[dir];
			int nz = get<0>(cur) + dz[dir];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M || nz < 0 || nz >= H) continue;
			if (board[nz][nx][ny] != 0) continue;
			if (dist[nz][nx][ny] >= 0) continue;

			dist[nz][nx][ny] = dist[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
			Q.push({ nz,nx,ny });
		}
	}

	int ans = 0;

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				ans = max(ans, dist[i][j][k]);

				if (dist[i][j][k] == -1) {
					cout << -1;
					return 0;
				}
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