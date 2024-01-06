//code from BaaaaaaaarkingDog
//pair<int,int> state[][] //{arrival time, color} 이용이 핵심

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define FIO ios::sync_with_stdio(0), cin.tie(0)
#define X first
#define Y second

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int N, M; // 행,열 <=50
int G, R; // 배양액 <=5		G+R<=10
int board[51][51]; // 0호수 1배양액x 2배양액o
vector<pair<int, int>> cand; //배양액의 위치
int candsz;  // 배양액을 놓을 수 있는 땅의 수

const int EMPTY = 0;
const int GREEN = 1;
const int RED = 2;
const int FLOWER = 3;

int subArr[11]; // permutation하기 위한 배열 

int solve() {

	int cnt = 0; //flower개수
	pair<int, int> state[51][51]; // {도착시간, 색깔}

	queue<pair<int, int>> Q;

	for (int i = 0; i < candsz; i++) {
		if (subArr[i] == GREEN || subArr[i] == RED) {
			state[cand[i].X][cand[i].Y] = { 0,subArr[i] };
			Q.push(cand[i]);
		}
	}

	while (!Q.empty()) {
		auto cur = Q.front(); Q.pop();

		int curtime = state[cur.X][cur.Y].X; // 도착시간
		int curcolor = state[cur.X][cur.Y].Y; //색깔
		if (state[cur.X][cur.Y].Y == FLOWER) continue;
		
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			if (board[nx][ny] == 0) continue;
			if (state[nx][ny].Y == EMPTY) {
				state[nx][ny] = { curtime + 1,curcolor };
				Q.push({ nx,ny });
			}
			else if (state[nx][ny].Y == GREEN) {
				if (curcolor == RED && state[nx][ny].X == curtime + 1) {
					cnt++;
					state[nx][ny].Y = FLOWER;
				}
			}
			else if (state[nx][ny].Y == RED) {
				if (curcolor == GREEN && state[nx][ny].X == curtime + 1) {
					cnt++;
					state[nx][ny].Y = FLOWER;
				}
			}
		}
	}
	return cnt;
}


int main() {

	FIO;

	cin >> N >> M >> G >> R;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			if (board[i][j] == 2)
				cand.push_back({ i,j });
		}
	}

	candsz = cand.size();

	for (int i = 0; i < candsz; i++) subArr[i] = EMPTY; // next_permutation에 사용할 subArr[] 설정
	for (int i = candsz - G - R; i < candsz - R; i++) subArr[i] = GREEN;
	for (int i = candsz - R; i < candsz; i++) subArr[i] = RED;

	int mx = 0;

	do {
		mx = max(mx, solve());
	} while (next_permutation(subArr, subArr + candsz));

	cout << mx;

	return 0;
}
