#include <iostream>
#include <algorithm>
#include <queue>
#define X first
#define Y second
using namespace std;
#define FIO ios::sync_with_stdio(0), cin.tie(0)


int N, M; 
int inputN[10]; //입력 수열
int outputN[10]; //출력 수열


void func(int cur) { 
	
	if (cur == M) {
		for (int i = 0; i < M; i++) cout << outputN[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 0; i < N; i++) {
		outputN[cur] = inputN[i];
		func(cur + 1);
	}
}

int main() {

	FIO;

	cin >> N >> M;

	for (int i = 0; i < N; i++) cin >> inputN[i];
	
	sort(inputN, inputN + N);

	func(0);

	return 0;
}
