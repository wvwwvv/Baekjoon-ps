//처음에 못풀었다.
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

int board[501][501];
int vis[501][501]; //0방문X
int N, M;
int mx, sum;

bool OOB(int x, int y) {
	if (x < 0 || x >= N || y < 0 || y >= M) return true;
	else return false;
}

void solve(int x, int y, int cnt) {
	//종료조건
	if (cnt == 4) {
		mx = max(mx, sum);
		return;
	}

	int nx, ny;

	for (int dir = 0; dir < 4; dir++) {
		nx = x + dx[dir];
		ny = y + dy[dir];
		if (OOB(nx, ny)) continue;
		if (vis[nx][ny] == 1) continue;
		vis[nx][ny] = 1;
		sum += board[nx][ny];
		solve(nx, ny, cnt + 1);

		//ㅗㅜㅏㅓ 처리하는 코드
		if (cnt == 2) { //처음 위치인 x,y로 돌아가면서..
			solve(x, y, cnt + 1);
		}

		vis[nx][ny] = 0;
		sum -= board[nx][ny];
	}
}

int main() {

	FIO;

	cin >> N >> M;


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j=0; j<M; j++) {
			sum = board[i][j];
			vis[i][j] = 1;
			solve(i, j, 1);
			vis[i][j] = 0;

		}
	}


	cout << mx;


	return 0;
}