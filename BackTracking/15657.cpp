#include <iostream>
#include <algorithm>
#include <queue>
#define X first
#define Y second
using namespace std;
#define FIO ios::sync_with_stdio(0), cin.tie(0)


int N, M; 
int inputN[10]; //입력 수열
//int outputN[10]; //출력 수열
int index[10];

void func(int cur) { 
	
	if (cur == M) {
		for (int i = 0; i < M; i++) cout << inputN[index[i]] << ' ';
		cout << '\n';
		return;
	}

	int start = 0;
	if (cur != 0) start = index[cur - 1];

	for (int i = start; i < N; i++) {
		index[cur] = i;
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
