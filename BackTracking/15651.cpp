#include <iostream>
#include <algorithm>
#include <queue>
#define X first
#define Y second
using namespace std;
#define FIO ios::sync_with_stdio(0), cin.tie(0)


int N, M; //N개의 수 중 M개 뽑기 - 중복가능
int arr[8];

void func(int cur) { 
	
	if (cur == M) {
		for (int i = 0; i < M; i++) cout << arr[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 0; i < N; i++) {
		arr[cur] = i + 1;
		func(cur + 1);
	}

}

int main() {

	FIO;

	cin >> N >> M;
	
	func(0);
	return 0;
}
