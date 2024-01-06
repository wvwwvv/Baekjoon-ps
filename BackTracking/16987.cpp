#include <iostream>
#include <algorithm>
#include <queue>
#define hp first
#define attack second
using namespace std;
#define FIO ios::sync_with_stdio(0), cin.tie(0)

int N; // N<=8
pair<int, int> egg[9];
int ans = 0; // 꺠진 계란의 수 최대값 갱신

void func(int cur, int broken) {

	if (cur == N) { //종료조건
		ans = max(ans, broken);
		return;
	}

	if (egg[cur].hp <= 0 || broken == N - 1) { //집은 계란이 깨졌거나 계란이 1개 남았을 때
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

		egg[cur].hp = egg[cur].hp + egg[i].attack; // 백트래킹. 이전상황으로 돌아가기
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
