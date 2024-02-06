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

void pushUp() { //���� �о�ֱ�

	for (int i = 0; i < N; i++) { //��
		clearCombined(); //combined : �� ������(��)���� �� ��ġ�� ���ڰ� ���������� ���� ����
		for (int j = 0; j < N; j++) { //��
			int x = j; //j�� ���̰� ���� ���� ������ ����
			int y = i;

			while (1) {
				if (x == 0) {
					break; // �� ������ �����Ƿ� break
				}

				if (board[x][y] == 0) break;

				if (board[x - 1][y] == 0) { //���� ���ڰ� ������ �� ĭ ����, �� �� while�� �ݺ�
					board[x - 1][y] = board[x][y];
					board[x][y] = 0;
					x--;
				}

				if (board[x - 1][y] != 0) { //���� ���ڰ� ������
					if ((board[x - 1][y] == board[x][y]) && (combined[x - 1] == false)) { //�պ����� ����
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

void rotate() { //�ð�������� 90�� ȸ��
	int temp[23][23];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			temp[i][j] = board[i][j];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			board[i][j] = temp[N - j - 1][i];

}


void execute(int dir) { //dir�� 0,1,2,3�̸� ��,��,��,������ �о������ �ǹ�
	
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