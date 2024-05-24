//BaaaaaaaarkingDog code
//slove()에서 재귀로 들어감. 단, ㅗ모양의 도형 처리하는 과정 유의하기. 재귀 끝까지 들어가고 리턴하면서 cnt가 2일때
//처음 시작 위치 좌표를 solve의 매개변수로 설정하는 디테일.
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

int dx[4] = { -1,0,1,0 }; //북, 동, 남, 서
int dy[4] = { 0,1,0,-1 };
int N;
int arr[12];
int oper[4]; //순서대로 + - * /

void solve(int& a, int b, int op) {

	if (op == 1) {
		a += b;
	}
	else if (op == 2) {
		a -= b;
	}
	else if (op == 3) {
		a *= b;
	}
	else {
		if (a < 0) {
			a *= -1;
			a /= b;
			a *= -1;
		}
		else {
			a /= b;
		}
	}
}

int main() {

	FIO;
	
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i];
	
	for (int i = 0; i < 4; i++)
		cin >> oper[i];

	vector<int> brute;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < oper[i]; j++) {
			brute.push_back(i + 1);
		}
	}

	int M, m; //max, min
	bool flag = true;
	do {
		int sum = arr[0];

		for (int i = 0; i < N - 1; i++) {
			solve(sum, arr[i+1], brute[i]);
		}

		if (flag) {
			M = sum;
			m = sum;
			flag = false;
		}

		M = max(M, sum);
		m = min(m, sum);

	} while (next_permutation(brute.begin(), brute.end()));

	cout << M << "\n" << m;

	return 0;
}