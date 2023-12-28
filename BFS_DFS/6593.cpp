#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <tuple>
#define FIO ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0)
#define X first
#define Y second

using namespace std;

int dx[6] = { 0,1,0,-1,0,0 };
int dy[6] = { 1,0,-1,0,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };

const int MX = 31;

int L, R, C; // L:�� �� R: ��, R: ��
string board[MX][MX];
int dist[MX][MX][MX];

int func() {

	while (true) {
		cin >> L >> R >> C;

		if (L == 0 && R == 0 && C == 0) return 0; //��������

		for (int i = 0; i < MX; i++) //�ʱ�ȭ
			for (int j = 0; j < MX; j++) {
				board[i][j] = {};
			}

		for (int i = 0; i < MX; i++) //�ʱ�ȭ
			for (int j = 0; j < MX; j++) 
				for (int k = 0; k < MX; k++)
					dist[i][j][k] = -1;
			
	
		queue<tuple<int, int, int>> Q; //(i,j,k)�� (����,��,��) �̰� (nz,nx,ny) �̸� (L,R,C) �̴�

		for (int i = 0; i < L; i++) {	//���� ������ �������� ť�� �ֱ�
			for (int j = 0; j < R; j++) {
				cin >> board[i][j];
				for (int k = 0; k < C; k++) {
					if (board[i][j][k] == 'S') {
						Q.push({ i,j,k });
						dist[i][j][k] = 0;
					}
				}
			}
		}

		bool findExit = false;

		while (!Q.empty()) {

			if (findExit == true) break;

			auto cur = Q.front(); Q.pop();

			for (int dir = 0; dir < 6; dir++) {
				int nx = get<1>(cur) + dx[dir];
				int ny = get<2>(cur) + dy[dir];
				int nz = get<0>(cur) + dz[dir];

				if (nx < 0 || nx >= R || ny < 0 || ny >= C || nz < 0 || nz >= L) continue;
				if (board[nz][nx][ny] == '#' || dist[nz][nx][ny] >= 0) continue;

				dist[nz][nx][ny] = dist[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
				Q.push({ nz,nx,ny });

				if (board[nz][nx][ny] == 'E') {
					findExit = true;
					cout << "Escaped in " << dist[nz][nx][ny] << " minute(s)." << '\n';
					break; // dir�� for�� ���
				}
				
			}
		}

		if (findExit == false) cout << "Trapped!" << '\n';
		
	}


	return 0;
}


int main() {
	
	FIO;

	func();

	
	return 0;
}