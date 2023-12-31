#include <iostream>
#include <algorithm>
#include <queue>
#define X first
#define Y second
using namespace std;
#define FIO ios::sync_with_stdio(0), cin.tie(0)

int N, M;
int arr[9]; // N <= 8  , 1~N�� ���� ����Ǿ��־� ���ǻ� index�� ������ 1�� ����
int ans[9]; // ���� ������ ���� �迭 
bool isused[9];

void func(int cur) {

	if (cur == M) {
		for (int i = 0; i < M; i++) cout << ans[i] << ' ';

		cout << "\n";
		return;
	}

	int start = 1;
	if (cur != 0) start = ans[cur - 1] + 1;

	for (int i = start; i <= N; i++) {
		if (isused[i]) continue;

		ans[cur] = arr[i];
		isused[i] = true;
		func(cur + 1);
		isused[i] = false;
		
	}
}

int main() {

	FIO;

	cin >> N >> M;

	for (int i = 1; i <= N; i++) arr[i] = i;

	func(0);

	return 0;
}
