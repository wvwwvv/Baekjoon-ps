#include <iostream>
#include <algorithm>
#include <queue>
#define X first
#define Y second
using namespace std;
#define FIO ios::sync_with_stdio(0), cin.tie(0)


int N, M; 
int inputN[10];
int arr[10];
bool isused[10];

void func(int cur) { 
	
	if (cur == M) {
		for (int i = 0; i < M; i++) cout << arr[i] << ' ';
		cout << '\n';
	}

	for (int i = 0; i < N; i++) {
		if (isused[i]) continue;

		arr[cur] = inputN[i];
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
