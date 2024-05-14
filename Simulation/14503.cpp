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

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

int board[51][51]; //0 : û�� X, 1: ��, 2: û�� O
int N, M;
int r, c, d; //d 0 1 2 3������ �� �� �� ��
int cleaned = 0; //û���� ĭ�� ����

bool OOB(int x, int y) {
	if (x < 0 || x >= N || y < 0 || y >= M) return true;
	else return false;
}

bool ableToGoBack(int x, int y) {
	//0:2, 1:3, 2:0, 3:1
	int backDir = (d + 2) % 4;

	if (OOB(x+dx[backDir], y+dy[backDir])) return false; 

	if (board[x + dx[backDir]][y + dy[backDir]] == 1) return false; //�����ϴ� ��ġ�� ���̸�

	//������ �� ������
	r = x + dx[backDir];
	c = y + dy[backDir];

	return true;
}

bool isEmpty(int x, int y) { //�����¿� �� �ϳ��� ��� true ��ȯ
	for (int dir = 0; dir < 4; dir ++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (OOB(nx,ny)) continue;
		if (board[nx][ny] == 0) return true;
	}

	return false;
}

int main() {

	FIO;

	cin >> N >> M;
	cin >> r >> c >> d;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> board[i][j];
	
	if (board[r][c] == 0) {
		board[r][c] = 2;
		cleaned++;
	}


	while (true) {
		if (isEmpty(r,c)) { //�����¿� ��ĭ �ִ� ���
			
			while(true) {
				if (d == 0) d = 3;	//�ݽð� ȸ��
				else d--;

				if (board[r + dx[d]][c + dy[d]] == 0) break;
			} 
			
			r = r + dx[d]; //����, û��
			c = c + dy[d];
			board[r][c] = 2;
			cleaned++;
		}
		else { //�����¿� ��ĭ ���� ���
			if (ableToGoBack(r, c)) { //���� �����ϸ� ����
				if (board[r][c] == 0) {
					board[r][c] = 2;
					cleaned++;
				}
			}
			else {
				cout << cleaned;
				return 0;
			}
		}

	}


	return 0;
}