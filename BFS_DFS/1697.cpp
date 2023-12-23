#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <tuple>
#define FIO ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0)
#define X first
#define Y second
using namespace std;


int N, K; // 0 <=  ����, ���� ��ġ <= 100000
int subin[100001]; //�����̰� index�� ��ġ�� ���µ� �ɸ��� �ð��� ����


int func() {

	cin >> N >> K;

	for (int i = 0; i < 100001; i++) subin[i] = -1; // -1�� �ǹ� : �ѹ��� �ش� index(��ġ)�� �������� ����

	subin[N] = 0;

	queue<int> Q;
	Q.push(N);

	while (subin[K] == -1) { //�����̰� ������ ��ġ�� �������� �ʾ��� �� ���ѷ���
		auto cur = Q.front(); Q.pop();

		for (int nxt : {cur - 1, cur + 1, 2 * cur}) {
			if (nxt < 0 || nxt > 100000) continue;
			if (subin[nxt] >= 0) continue; //������ ���� ������ ���� �װ��� �� �� �ʿ䰡 ����, �ִܽð��� ���ϱ� ����
			subin[nxt] = subin[cur] + 1;
			Q.push(nxt);
		}
	}

	cout << subin[K];
	return 0;

}


int main() {
	
	FIO;

	func();

	return 0;
}