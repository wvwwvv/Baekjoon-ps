#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
#define FIO ios::sync_with_stdio(0), cin.tie(0)
#define X first
#define Y second

int N;
string board[65]; // 0: 흰 1: 검


bool check(int x, int y, int n) {
	for (int i = x; i < x + n; i++)
		for (int j = y; j < y + n; j++)
			if (board[x][y] != board[i][j]) return false;

	return true;
}

void func(int a, int b, int n) {
	if (check(a, b, n)) { //종료조건
		cout << board[a][b];
		return;
	}

	cout << "(";

	n = n / 2;
	
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++) 
			func(a + i * n, b + j * n, n);
			
	cout << ")";

	return;
}


int main() {

	FIO;

	cin >> N;

	for (int i = 0; i < N; i++)
			cin >> board[i];


	func(0, 0, N);


	return 0;
}