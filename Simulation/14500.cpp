//ó���� ��Ǯ����.
//BaaaaaaaarkingDog code
//slove()���� ��ͷ� ��. ��, �Ǹ���� ���� ó���ϴ� ���� �����ϱ�. ��� ������ ���� �����ϸ鼭 cnt�� 2�϶�
//ó�� ���� ��ġ ��ǥ�� solve�� �Ű������� �����ϴ� ������.
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

int dx[4] = { -1,0,1,0 }; //��, ��, ��, ��
int dy[4] = { 0,1,0,-1 };

int board[501][501];
int vis[501][501]; //0�湮X
int N, M;
int mx, sum;

bool OOB(int x, int y) {
	if (x < 0 || x >= N || y < 0 || y >= M) return true;
	else return false;
}

void solve(int x, int y, int cnt) {
	//��������
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

		//�Ǥ̤��� ó���ϴ� �ڵ�
		if (cnt == 2) { //ó�� ��ġ�� x,y�� ���ư��鼭..
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