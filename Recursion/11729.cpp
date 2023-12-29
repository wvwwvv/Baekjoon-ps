#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
#define FIO ios::sync_with_stdio(0), cin.tie(0)
#define X first
#define Y second

//n개의 원판이 있을 때, n-1개의 원판을 두 번째 접시에 옮긴다. -> 가장 큰 원판을 세 번째 접시에 옮긴다. -> n-1개의 원판을 그대로 세 번째 접시에 옮긴다.

int N;
int num = 0;
vector<pair<int, int>> V;

void func(int a, int b, int n) { // a: 시작점 b: 옮길 지점 n: 원판의 개수

	num++; //함수가 호출되는 횟수 : 원판을 옮긴 횟수

	if (n == 1) {
		V.push_back({ a,b });
		return;
	}

	func(a, 6 - a - b, n - 1); // 이 문제에서는 쟁반이 1,2,3이 있으므로 6-a-b는 a도, b도 아닌 쟁반을 의미
	V.push_back({a,b}); // 가장 큰 원판을 세 번째 접시에 옮기는 과정
	func(6 - a - b, b, n - 1);

	return;
}


int main() {

	FIO;
	
	cin >> N;
	
	
	func(1,3,N);

	cout << num << '\n';

	for (auto v : V) cout << v.X << " " << v.Y << '\n';

	return 0;
}