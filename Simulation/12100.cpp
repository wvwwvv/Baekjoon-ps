#include <iostream>
#include <cstdlib>
#include <math.h>
#include <algorithm>
#include <queue>
using namespace std;
#define FIO ios::sync_with_stdio(0), cin.tie(0);
#define X first
#define Y second

int N;
int board0[23][23];
int board[23][23]; 
bool combined[23];

void B_print() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << board[i][j] << ' ';
		}
		cout << "\n";
	}
	cout << "\n";
}

void clearCombined() {
	for (int i = 0; i < N; i++) combined[i] = false;
}

void pushUp() { //위로 밀어넣기

	for (int i = 0; i < N; i++) { //열
		clearCombined(); //combined : 매 세로줄(열)마다 각 위치의 숫자가 합쳐졌는지 여부 저장
		for (int j = 0; j < N; j++) { //행
			int x = j; //j가 행이고 행을 먼저 접근할 것임
			int y = i;

			while (1) {
				if (x == 0) {
					break; // 맨 위까지 왔으므로 break
				}

				if (board[x][y] == 0) break;

				if (board[x - 1][y] == 0) { //위에 숫자가 없으면 한 칸 위로, 이 때 while문 반복
					board[x - 1][y] = board[x][y];
					board[x][y] = 0;
					x--;
				}

				if (board[x - 1][y] != 0) { //위에 숫자가 있으면
					if ((board[x - 1][y] == board[x][y]) && (combined[x - 1] == false)) { //합병가능 조건
						board[x - 1][y] *= 2;
						board[x][y] = 0;
						combined[x - 1] = true;
					}
					break;
				}
			}
		}
	}
}

void rotate() { //시계방향으로 90도 회전
	int temp[23][23];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			temp[i][j] = board[i][j];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			board[i][j] = temp[N - j - 1][i];

}


void execute(int dir) { //dir가 0,1,2,3이면 북,서,남,동으로 밀어넣음을 의미
	
	for (int i = 0; i < dir; i++) rotate();

	pushUp();

	for (int i = 0; i < 4 - dir; i++) rotate();
}




int main() {

	FIO;

	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> board0[i][j];

	int mx = 0;

	for (int tmp = 0; tmp < 1024; tmp++) {
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				board[i][j] = board0[i][j];
		int brute = tmp;
		for (int i = 0; i < 5; i++) {
			int dir = brute % 4;
			brute /= 4;
			execute(dir);
		}
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				mx = max(mx, board[i][j]);
	}

	cout << mx;



	/*int cmd;

	while (1) {
		cout << "0 1 2 3 : N W S E\n";
		cout << "insert 5 to exit\n";
		cin >> cmd;
		if (cmd == 5) break;

		cout << "\n";

		execute(cmd);
		system("cls");

		B_print();
	}*/


	return 0;
}