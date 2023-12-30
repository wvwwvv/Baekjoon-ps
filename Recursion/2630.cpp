#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
#define FIO ios::sync_with_stdio(0), cin.tie(0)
#define X first
#define Y second

int N;
int board[130][130];
int ans[2]; //ans[0] : 하얀색 ans[1] : 파란색

bool check(int x, int y, int n) {
	for (int i = x; i < x + n; i++)
		for (int j = y; j < y + n; j++)
			if (board[x][y] != board[i][j]) return false;

	return true;
}

void func(int a, int b, int n) {
	if (check(a, b, n)) { //종료조건
		ans[board[a][b]]++;
		return;
	}

	n = n / 2;
	
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			func(a + i * n, b + j * n, n);

	return;
}


int main() {

	FIO;

	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];


	func(0, 0, N);

	cout << ans[0] << '\n' << ans[1];

	return 0;
}