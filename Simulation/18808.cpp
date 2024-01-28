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
int r, c; //paper의 행과 열
int paper[12][12];


void rotate() { // paper 90도 회전
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


bool pastable(int x, int y) { // board의 (x,y)에 paper의 (0,0) 을 붙일 수 있는지 판단, 붙일 수 있다면 board 갱신

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
			bool isPaste = false; //스티커를 붙였는지

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
			rotate(); //스티커를 붙이지 못했으면
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