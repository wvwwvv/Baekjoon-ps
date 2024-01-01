#include <iostream>
#include <algorithm>
#include <queue>
#define X first
#define Y second
using namespace std;
#define FIO ios::sync_with_stdio(0), cin.tie(0)


int N, M; 
int arr[8];

void func(int cur, int start) { 
	
	if (cur == M) {
		for (int i = 0; i < M; i++) cout << arr[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = start; i <= N; i++) {
		arr[cur] = i;
		func(cur + 1, i);
	}
}

int main() {

	FIO;

	cin >> N >> M;
	
	func(0,1);

	return 0;
}
