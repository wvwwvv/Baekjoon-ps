//BaaaaaaaarkingDog code
//slove()에서 재귀로 들어감. 단, ㅗ모양의 도형 처리하는 과정 유의하기. 재귀 끝까지 들어가고 리턴하면서 cnt가 2일때
//처음 시작 위치 좌표를 solve의 매개변수로 설정하는 디테일.
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <math.h>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
#define FIO ios::sync_with_stdio(0), cin.tie(0);
#define X first
#define Y second

//int dx[6] = { 0,1,0,-1,0,0 };
//int dy[6] = { 1,0,-1,0,0,0 };
//int dz[6] = { 0,0,0,0,1,-1 };

int dx[4] = { -1,0,1,0 }; //북, 동, 남, 서
int dy[4] = { 0,1,0,-1 };
int n, m;
int board[9][9]; //0빈칸 1벽 2바이러스
int tmp[9][9], vis[9][9];

vector<pair<int, int>> zero;
queue<pair<int, int>> virus;

void clearBoard() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			board[i][j] = tmp[i][j];
			vis[i][j] = 0;
			if (board[i][j] == 2) virus.push({ i,j });
		}
	}
}

int bfs() {
	int ans = 0;

	queue<pair<int, int>> q;

	while (!virus.empty()) {
		q.push(virus.front());
		virus.pop();

	}

	while (!q.empty()) {
		auto cur = q.front(); q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (vis[nx][ny] == 1 || board[nx][ny] != 0) continue;
			board[nx][ny] = 2;
			vis[nx][ny] = 1;
			q.push({ nx,ny });
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 0) ans++;
		}
	}


	return ans;

}

int main() {

	FIO;
		
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			tmp[i][j] = board[i][j];
			if (board[i][j] == 0) zero.push_back({ i,j });
			if (board[i][j] == 2) virus.push({ i,j });
		}
	}

	vector<int> brute(zero.size(), 1);
	fill(brute.begin(), brute.end() - 3, 0); //끝에 3개만 1

	int mx = 0;

	do {
		clearBoard();
		for (int i = 0; i < brute.size(); i++) {
			if (brute[i] == 1)
				board[zero[i].X][zero[i].Y] = 1; //벽 3개 조합으로 설정
		}
		mx = max(mx, bfs());

	} while (next_permutation(brute.begin(), brute.end()));

	cout << mx;

	return 0;
}