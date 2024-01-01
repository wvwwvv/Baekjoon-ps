#include <iostream>
#include <algorithm>
#include <queue>
#define X first
#define Y second
using namespace std;
#define FIO ios::sync_with_stdio(0), cin.tie(0)

//각 행에는 단 하나의 퀸이 무조건 존재해야함

int N; //N < 15
int ans = 0;

bool isused1[15]; // 세로
bool isused2[30]; //하나의 우상향 대각선에 속하는 (행,열)에서 행+열이 일정하다 ex) (3,1)과 (2,2)는 행+열이 4이므로 같은 대각선에 위치해 있고
				  //isused[4]의 값을 참조해 해당 대각선에 퀸의 존재 여부를 판단한다
bool isused3[30]; //하나의 우하향 대각선에 속하는 (행,열)에서 행-열이 일정하다

void func(int cur) { //cur: 현재 행
	 
	//행을 뜻하는 cur을 이용해 접근하므로 각 행 (가로)에 다른 퀸이 존재하는지 여부를 판단할 필요가 없도록 설계함
	//세로(열), 우상향 대각선, 우하향 대각선 총 3가지만 확인하면 됨

	if (cur == N) {	//종료조건
		ans++;
		return;
	}


	for (int i = 0; i < N; i++) { // i : 열
		if (isused1[i] || isused2[cur + i] || isused3[cur - i + N - 1]) continue; 

		isused1[i] = true;
		isused2[cur + i] = true;
		isused3[cur - i + N - 1] = true;
		func(cur + 1);
		isused1[i] = false;
		isused2[cur + i] = false;
		isused3[cur - i + N - 1] = false;


	}

}

int main() {

	FIO;

	cin >> N;

	func(0);

	cout << ans;

	return 0;
}
