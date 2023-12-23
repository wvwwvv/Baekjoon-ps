#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <tuple>
#define FIO ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0)
#define X first
#define Y second
using namespace std;


int N, K; // 0 <=  수빈, 동생 위치 <= 100000
int subin[100001]; //수빈이가 index의 위치에 가는데 걸리는 시간을 저장


int func() {

	cin >> N >> K;

	for (int i = 0; i < 100001; i++) subin[i] = -1; // -1의 의미 : 한번도 해당 index(위치)에 도달하지 않음

	subin[N] = 0;

	queue<int> Q;
	Q.push(N);

	while (subin[K] == -1) { //수빈이가 동생의 위치에 도착하지 않았을 때 무한루프
		auto cur = Q.front(); Q.pop();

		for (int nxt : {cur - 1, cur + 1, 2 * cur}) {
			if (nxt < 0 || nxt > 100000) continue;
			if (subin[nxt] >= 0) continue; //도착한 적이 있으면 굳이 그곳에 또 갈 필요가 없음, 최단시간을 구하기 때문
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