//code from BaaaaaaaarkingDog
//pair<int,int> state[][] //{arrival time, color} �̿��� �ٽ�

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define FIO ios::sync_with_stdio(0), cin.tie(0)
#define X first
#define Y second

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int N, M; // ��,�� <=50
int G, R; // ���� <=5		G+R<=10
int board[51][51]; // 0ȣ�� 1����x 2����o
vector<pair<int, int>> cand; //������ ��ġ
int candsz;  // ������ ���� �� �ִ� ���� ��

const int EMPTY = 0;
const int GREEN = 1;
const int RED = 2;
const int FLOWER = 3;

int subArr[11]; // permutation�ϱ� ���� �迭 

int solve() {

	int cnt = 0; //flower����
	pair<int, int> state[51][51]; // {�����ð�, ����}

	queue<pair<int, int>> Q;

	for (int i = 0; i < candsz; i++) {
		if (subArr[i] == GREEN || subArr[i] == RED) {
			state[cand[i].X][cand[i].Y] = { 0,subArr[i] };
			Q.push(cand[i]);
		}
	}

	while (!Q.empty()) {
		auto cur = Q.front(); Q.pop();

		int curtime = state[cur.X][cur.Y].X; // �����ð�
		int curcolor = state[cur.X][cur.Y].Y; //����
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

	for (int i = 0; i < candsz; i++) subArr[i] = EMPTY; // next_permutation�� ����� subArr[] ����
	for (int i = candsz - G - R; i < candsz - R; i++) subArr[i] = GREEN;
	for (int i = candsz - R; i < candsz; i++) subArr[i] = RED;

	int mx = 0;

	do {
		mx = max(mx, solve());
	} while (next_permutation(subArr, subArr + candsz));

	cout << mx;

	return 0;
}
