#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
#define FIO ios::sync_with_stdio(0), cin.tie(0)
#define X first
#define Y second

//n���� ������ ���� ��, n-1���� ������ �� ��° ���ÿ� �ű��. -> ���� ū ������ �� ��° ���ÿ� �ű��. -> n-1���� ������ �״�� �� ��° ���ÿ� �ű��.

int N;
int num = 0;
vector<pair<int, int>> V;

void func(int a, int b, int n) { // a: ������ b: �ű� ���� n: ������ ����

	num++; //�Լ��� ȣ��Ǵ� Ƚ�� : ������ �ű� Ƚ��

	if (n == 1) {
		V.push_back({ a,b });
		return;
	}

	func(a, 6 - a - b, n - 1); // �� ���������� ����� 1,2,3�� �����Ƿ� 6-a-b�� a��, b�� �ƴ� ����� �ǹ�
	V.push_back({a,b}); // ���� ū ������ �� ��° ���ÿ� �ű�� ����
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