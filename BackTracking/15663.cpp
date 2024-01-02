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

void func(int cur) { 
	
	if (cur == M) {
		for (int i = 0; i < M; i++) cout << outputN[i] << ' ';
		cout << '\n';
		return;
	}

	int temp = 0; //�ߺ��� �������� Ȯ���� �� ���

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
