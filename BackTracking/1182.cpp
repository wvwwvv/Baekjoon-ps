#include <iostream>
#include <algorithm>
#include <queue>
#define X first
#define Y second
using namespace std;
#define FIO ios::sync_with_stdio(0), cin.tie(0)

int N, S;
int arr[21];
int ans = 0;

void func(int cur, int total) { 
	
	if (cur == N) {
		if (total == S) {
			ans++;
			return;
		}
		return;
	}

	func(cur + 1, total + arr[cur]);
	func(cur + 1, total);

}

int main() {

	FIO;

	cin >> N >> S;

	for (int i = 0; i < N; i++) cin >> arr[i];

	func(0,0);

	if (S == 0) cout << ans - 1; // S가 0이면 공집합도 포함됨
	else cout << ans;

	return 0;
}
