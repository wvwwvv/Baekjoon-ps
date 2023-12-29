#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
#define FIO ios::sync_with_stdio(0), cin.tie(0)
#define X first
#define Y second


int N;  //N<= 2187
int board[2190][2190];
int ans[3]; //-1,0,1의 갯수


bool check(int x, int y, int n) {
	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y + n; j++) {
			if (board[x][y] != board[i][j]) return false;
		}
	}

	return true;

}


void func(int x, int y, int n) { //n: 한변 
	
	if (check(x,y,n)) { //모두 같은 수일 때 종료조건 만족
		ans[board[x][y] + 1] ++;
		return;
	}

	n = n / 3;

	//9개의 분면에 대해 각각 모두 재귀 필요

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			func(x + i * n, y + j * n, n);

}


int main() {

	FIO;

	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];

	func(0, 0, N);

	cout << ans[0] << '\n' << ans[1] << '\n' << ans[2];

	return 0;
}