#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
#define FIO ios::sync_with_stdio(0), cin.tie(0)
#define X first
#define Y second

int N; // <= 3072
char board[3100][6200]; 


void draw(int x, int y) {
	board[x][y] = '*';
	board[x + 1][y - 1] = '*', board[x + 1][y + 1] = '*';
	for (int i = y - 2; i <= y + 2; i++) board[x + 2][i] = '*';
}

void func(int a, int b, int n) { // (a,b) : 왼쪽 위 시작점
	
	if (n == 3) {
		draw(a, b);
		return;
	}

	n = n / 2;

	func(a, b, n);
	func(a + n, b - n, n);
	func(a + n, b + n, n);
	
}


int main() {

	FIO;

	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < 2 * N - 1; j++) board[i][j] = ' ';
	
	func(0, N - 1, N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 2 * N - 1; j++) {
			cout << board[i][j];
		}
		cout << '\n';
	}

	return 0;
}