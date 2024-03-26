#include <iostream>
#include <cstdlib>
#include <ctime>
#include <math.h>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
#define FIO ios::sync_with_stdio(0), cin.tie(0);
#define X first
#define Y second

int n, w, L;
int cnt = 0; //시행 수
int weight = 0; //다리 하중
queue<int> q; //다리 위에 있지 않은 트럭의 무게
vector<pair<int, int>> v; //다리 위에 있는 트럭의 무게, 위치 저장. ex) w==2인 다리에서 위치값이 0,1인 경우 다리 위에 있다.

int main() {

	FIO;

	cin >> n >> w >> L;

	while (n--) {
		int a;
		cin >> a;
		q.push(a);
	}

	do {
		for (int i = 0; i < v.size(); i++) { //다리 위 트럭만 한칸 전진
			v[i].Y += 1;
		}

		for (int i = 0; i < v.size(); i++) {
			if (v[i].Y >= w)
				v[i].X = 0; //빠져나간 트럭의 무게 0으로 설정
		}

		if (!v.empty()) {
			weight = 0;
			for (int i = 0; i < v.size(); i++) //다리 위 무게 갱신
				weight += v[i].X;
		}
		
		if (q.front() <= L - weight) { //다리밖 트럭이 다리로 올라갈 수 있으면
			int tmp = q.front(); q.pop();
			v.push_back({ tmp, 0 }); //그 트럭을 v벡터에 넣음
		}

		cnt++;
			
	} while (!q.empty());

	//다리위로 마지막 트럭이 올라간 순간, 그 트럭이 빠져나갈 시행 : w
	cnt += w;

	cout << cnt;

	return 0;
}