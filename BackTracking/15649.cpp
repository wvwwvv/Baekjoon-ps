#include <iostream>
#include <algorithm>
#include <queue>
#define X first
#define Y second
using namespace std;
#define FIO ios::sync_with_stdio(0), cin.tie(0)

int N, M;
int arr[9]; // N <= 8
int ans[9]; // 뽑은 순열을 넣을 배열 
bool vis[9];

void func(int cur) {

	if (cur == M) {
		for (int i = 0; i < M; i++) cout << ans[i] << ' ';

		cout << "\n";
		return;
	}


	for (int i = 1; i <= N; i++) {
		if (vis[i]) continue;

		ans[cur] = arr[i];
		vis[i] = true;
		func(cur + 1);
		vis[i] = false;
	}
}

int main() {

	FIO;

	cin >> N >> M;

	for (int i = 1; i <= N; i++) arr[i] = i;

	func(0);

	return 0;
}
