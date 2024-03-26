#include <iostream>
#include <cstdlib>
#include <ctime>
#include <math.h>
#include <algorithm>
#include <queue>
using namespace std;
#define FIO ios::sync_with_stdio(0), cin.tie(0);
#define X first
#define Y second

string wheel[4];
int N;

void go(int x, int dir) { //x: (x+1) 톱니, dir : 방향
	int dirs[4] = {}; //각 톱니의 회전 방향 1,0,-1
	dirs[x] = dir;

	int idx = x;
	//왼쪽으로 회전 전파
	while (idx > 0 && wheel[idx][6] != wheel[idx - 1][2]) { //현재 톱니와 왼쪽 톱니가 닿는 극이 다를때
		dirs[idx - 1] = -dirs[idx];
		idx--;
	}

	idx = x;
	//오른쪽으로 회전 전파
	while (idx < 3 && wheel[idx][2] != wheel[idx + 1][6]) {
		dirs[idx + 1] = -dirs[idx];
		idx++;
	}

	for (int i = 0; i < 4; i++) {
		if (dirs[i] == -1) { //반시계, 앞을 맨 뒤로
			rotate(wheel[i].begin(), wheel[i].begin() + 1, wheel[i].end()); //왼쪽으로 1칸 이동
		}
		else if (dirs[i] == 1) {
			rotate(wheel[i].begin(), wheel[i].begin() + 7, wheel[i].end()); //왼쪽으로 7칸 이동 (-1칸 이동)
		}
	}

}


int main() {

	FIO;

	//시계방향 : 끝이 앞으로
	//반시계방향 : 앞이 끝으로

	for (int i = 0; i < 4; i++)
		cin >> wheel[i];

	cin >> N;

	while (N--) {
		int wheelNum;
		int dir;

		cin >> wheelNum >> dir;

		go(wheelNum - 1, dir);
	}

	int score = 0;

	for (int i = 0; i < 4; i++) {
		if (wheel[i][0] == '1') score += pow(2, i);
	}

	cout << score;

	return 0;
}