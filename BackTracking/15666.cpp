#include <iostream>
#include <algorithm>
#include <queue>
#define X first
#define Y second
using namespace std;
#define FIO ios::sync_with_stdio(0), cin.tie(0)


int N, M; 
int inputN[10]; //�Է� ����
int outputN[10]; //��� ����
int index[10]; //inputN�� outputN�� �����Ҷ� 
bool isused[10];

void func(int cur, int start) { 
	
	if (cur == M) {
		for (int i = 0; i < M; i++) cout << outputN[i] << ' ';
		cout << '\n';
		return;
	}

	int temp = 0; // �ߺ����� ó��

	for (int i = start; i < N; i++) {
		if (temp == inputN[i]) continue;

		outputN[cur] = inputN[i];
		temp = outputN[cur];
		func(cur + 1, i);
	}
	
	
}

int main() {

	FIO;

	cin >> N >> M;

	for (int i = 0; i < N; i++) cin >> inputN[i];
	
	sort(inputN, inputN + N);

	func(0,0);

	return 0;
}
