#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
#define FIO ios::sync_with_stdio(0), cin.tie(0)
#define X first
#define Y second

int N; //<2187
char board[2200][2200]; 


void draw(int x, int y) {
	for (int i = x; i < x + 3; i++)
		for (int j = y; j < y + 3; j++) {
			if (i == x + 1 && j == y + 1) board[i][j] = ' ';
			else board[i][j] = '*';
		}
}

void func(int a, int b, int n) { // (a,b) : 왼쪽 위 시작점
	
	if (n == 3) {
		draw(a, b);
		return;
	}

	n = n / 3;

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) {
			if (i == 1 && j == 1) continue;

			func(a + i * n, b + j * n, n);
		}

	
}


int main() {

	FIO;

	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) board[i][j] = ' ';

	func(0, 0, N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << board[i][j];
		}
		cout << '\n';
	}

	return 0;
}