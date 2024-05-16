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

//int dx[6] = { 0,1,0,-1,0,0 };
//int dy[6] = { 1,0,-1,0,0,0 };
//int dz[6] = { 0,0,0,0,1,-1 };

int dx[4] = { -1,0,1,0 }; //북, 동, 남, 서
int dy[4] = { 0,1,0,-1 };

int N, K, L; //한 변, 사과 개수, 방향 전환
int board[101][101]; //1사과 2뱀
int dir = 1; //초기 방향 동
int ans = 0;
deque <pair<int, int>> snake;
queue<pair<int, char>> changDir; //L왼 D오른

int main() {

	FIO;

	cin >> N >> K;

	while (K--) { //사과
		int x, y;
		cin >> x >> y;
		board[x][y] = 1;
	}

	cin >> L;

	while (L--) { //방향전환
		int a;
		char b;
		cin >> a >> b;
		changDir.push({ a,b });
	}

	snake.push_front({ 1,1 }); //뱀의 처음 위치

	while (true) {
		
		auto cur = snake.front();

		board[cur.X][cur.Y] = 2; //뱀의 머리 이동
		ans++;

		int nx = cur.X + dx[dir];
		int ny = cur.Y + dy[dir];

		if (nx<1 || nx>N || ny<1 || ny>N || board[nx][ny] == 2) break;

		//사과 있으면 tail 건들 필요없고

		//사과 없으면
		if (board[nx][ny] != 1) {
			auto tail = snake.back();
			board[tail.X][tail.Y] = 0; //꼬리가 줄어듦 
			snake.pop_back();
		}

		//여기서 ans값만큼 시간이 지나게 됨

		auto cmd = changDir.front();

		if (cmd.X == ans) {
			if (cmd.Y == 'L') dir += 3; //왼쪽으로 90도 회전(반시계)
			else dir += 1; //시계
			changDir.pop();
			dir %= 4;
		}

		snake.push_front({ nx,ny });
	}

	cout << ans;

	return 0;
}