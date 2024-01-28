#include <iostream>
#include <math.h>
#include <algorithm>
#include <queue>
using namespace std;
#define FIO ios::sync_with_stdio(0), cin.tie(0);
#define X first
#define Y second

int dx[4] = { 1,0,-1,0 }; //순서대로 남, 동, 북, 서
int dy[4] = { 0,1,0,-1 };

int N, M;
int board1[10][10];
int board2[10][10];
vector<pair<int, int>> cctv; //cctv 좌표 저장


bool OOB(int x, int y) { // out of bounds 체크, 이런 사소한 것도 함수로 만들어 놓는것이 편리
	return x < 0 || y < 0 || x >= N || y >= M;
}

void go_dir(int x, int y, int dir) { // dir 방향으로 cctv 감시, dir가  0:남, 1:동, 2:북, 3:서
	dir = dir % 4;

	while (1) {
		x += dx[dir];
		y += dy[dir];
		if (OOB(x, y) || board2[x][y] == 6) return; //범위를 벗어나거나 벽을 만나면 리턴
		if (board2[x][y] != 0) continue; // 해당 칸이 빈칸이 아니면 continue
		board2[x][y] = 7; //감시 가능 영역은 7로 덮음
	}
}


int main() {

	FIO;

	cin >> N >> M;

	int mn = 0; //사각지대 크기

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board1[i][j];
			if (board1[i][j] != 0 && board1[i][j] != 6)
				cctv.push_back({ i,j });
			if (board1[i][j] == 0)
				mn++;
		}
	}

	// cctv의 개수가 만약 4개이면, 4의 4제곱만큼 반복해야함 -> 모든 방향에 대한 경우의수를 확인하기 위해, 중복되는 상황까지 모두 보는것이 편리

	int c_size = cctv.size();
	int iter = 1;

	for (int i = 0; i < c_size; i++)
		iter = iter * 4;

	for (int temp = 0; temp < iter; temp++) { //모든 경우의 수 다 훑기

		for (int i = 0; i < N; i++) //각 temp마다 서로 다른 시행(서로 다른 사각지대의 크기를 가짐)이므로 board2를 매번 복사한다.
			for (int j = 0; j < M; j++)
				board2[i][j] = board1[i][j];

		//매우 중요!!
		//temp는 (0) ~ (4의 거듭제곱 - 1) 까지의 수이므로 4진법으로 나타낼 수 있으며 가장 큰 자리수는 c_size와 같다.
		//즉, temp의 각 자리수는 각각의 cctv가 가리키는 방향이라고 생각할 수 있다.
		//예를 들어, temp % 4의 값은 첫번째 cctv가 가리키는 방향이다. (temp/4) % 4 는 두번째 cctv가 가리키는 방향이다.

		int num = temp;

		for (int i = 0; i < c_size; i++) {
			int dir = num % 4; //첫 for문에서 dir가 의미하는 것 : 첫번째 cctv가 가리키는 방향
			num = num / 4;
			int x = cctv[i].X;
			int y = cctv[i].Y;

			if (board1[x][y] == 1) {
				go_dir(x, y, dir);
			}
			else if (board1[x][y] == 2) {
				go_dir(x, y, dir);
				go_dir(x, y, dir+2);
			}
			else if (board1[x][y] == 3) {
				go_dir(x, y, dir);
				go_dir(x, y, dir+1);
			}
			else if (board1[x][y] == 4) {
				go_dir(x, y, dir);
				go_dir(x, y, dir+1);
				go_dir(x, y, dir+2);
			}
			else if (board1[x][y] == 5) {
				go_dir(x, y, dir);
				go_dir(x, y, dir+1);
				go_dir(x, y, dir+2);
				go_dir(x, y, dir+3);
			}
		} //모든 cctv의 방향에 따라 훑어 사각지대가 결정됨

		int val = 0;

		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				if (board2[i][j] == 0)
					val++;

		mn = min(mn, val); //iter마다 mn 최솟값 갱신

	} // iter만큼의 반복 끝

	cout << mn;

}
