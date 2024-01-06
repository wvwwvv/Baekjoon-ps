#include <iostream>
#include <algorithm>
#include <queue>
#define hp first
#define attack second
using namespace std;
#define FIO ios::sync_with_stdio(0), cin.tie(0)

int N; // N<=8
pair<int, int> egg[9];
int ans = 0; // ���� ����� �� �ִ밪 ����

void func(int cur, int broken) {

	if (cur == N) { //��������
		ans = max(ans, broken);
		return;
	}

	if (egg[cur].hp <= 0 || broken == N - 1) { //���� ����� �����ų� ����� 1�� ������ ��
		func(cur + 1, broken);
		return;
	}
	

	for (int i = 0; i < N; i++) {
		if (i == cur || egg[i].hp <= 0) continue;

		egg[cur].hp = egg[cur].hp - egg[i].attack;
		egg[i].hp = egg[i].hp - egg[cur].attack;

		if (egg[cur].hp <= 0) broken++;
		if (egg[i].hp <= 0) broken++;

		func(cur + 1, broken);

		if (egg[cur].hp <= 0) broken--;
		if (egg[i].hp <= 0) broken--;

		egg[cur].hp = egg[cur].hp + egg[i].attack; // ��Ʈ��ŷ. ������Ȳ���� ���ư���
		egg[i].hp = egg[i].hp + egg[cur].attack;
		
	}

}


int main() {

	FIO;

	cin >> N;

	for (int i = 0; i < N; i++) cin >> egg[i].hp >> egg[i].attack;

	func(0, 0);

	cout << ans;

	return 0;
}
