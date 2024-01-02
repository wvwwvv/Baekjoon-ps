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
int index[10]; //inputN과 outputN에 접근할때 
bool isused[10];

void func(int cur) { 
	
	if (cur == M) {
		for (int i = 0; i < M; i++) cout << outputN[i] << ' ';
		cout << '\n';
		return;
	}

	int temp = 0; //중복된 수열인지 확인할 때 사용

	for (int i = 0; i < N; i++) {
		if (isused[i] || temp == inputN[i]) continue;

		outputN[cur] = inputN[i];
		temp = outputN[cur];
		isused[i] = true;
		func(cur + 1);
		isused[i] = false;
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
