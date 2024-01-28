//from BaaaaaaaarkingDog
#include <iostream>
#include <math.h>
#include <algorithm>
#include <queue>
using namespace std;
#define FIO ios::sync_with_stdio(0), cin.tie(0);
#define X first
#define Y second

int dx[4] = { 1,0,-1,0 }; 
int dy[4] = { 0,1,0,-1 };

int N, M, K;
int board[42][42];
int r, c; //paper�� ��� ��
int paper[12][12];


void rotate() { // paper 90�� ȸ��
	int temp[12][12];

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			temp[i][j] = paper[i][j];
		}
	}

	for (int i = 0; i < c; i++) {
		for (int j = 0; j < r; j++) {
			paper[i][j] = temp[r-1-j][i];
		}
	}

	swap(r, c);
}


bool pastable(int x, int y) { // board�� (x,y)�� paper�� (0,0) �� ���� �� �ִ��� �Ǵ�, ���� �� �ִٸ� board ����

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (board[x + i][y + j] == 1 && paper[i][j] == 1)
				return false;
		}
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (paper[i][j] == 1)
				board[x + i][y + j] = 1;
		}
	}

	return true;

}

int main() {

	FIO;

	cin >> N >> M >> K;

	while (K--) {
		cin >> r >> c;

		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				cin >> paper[i][j];


		for (int rot = 0; rot < 4; rot++) {
			bool isPaste = false; //��ƼĿ�� �ٿ�����

			for (int x = 0; x <= N - r; x++) {
				for (int y = 0; y <= M - c; y++) {
					if (isPaste) break; 

					if (pastable(x, y)) {
						isPaste = true;
						break;
					}
				}
			}

			if (isPaste) break;
			rotate(); //��ƼĿ�� ������ ��������
		}
	}

	int cnt = 0; 

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (board[i][j] == 1)
				cnt++;

	cout << cnt;
	return 0;
				
}