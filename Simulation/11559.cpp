//빈 칸을 아래로 내리는 방법, puyo 함수 내에서 bfs가 성공할 때마다 vector 타입의 tmp에 해당 위치 저장 -> 4개이상 조건 충족시 그 위치 모두 .로 변경
//bfs 시작할 위치 고민 -> .이 아니고, 방문한 적 없는 곳

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

bool isPuyo; //뿌요 터졌는지
string board[12];
bool vis[12][6];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int ans = 0;

void resetVis() {
	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 6; j++)
			vis[i][j] = false;
}

void puyo(int x, int y) {
	vis[x][y] = true;
	char color = board[x][y];

	queue<pair<int, int>> q; //bfs
	vector<pair<int, int>> tmp; // 4개 이상 붙어있으면 삭제할 위치 저장
	q.push({ x,y });
	tmp.push_back({ x,y });

	while (!q.empty()) {
		auto cur = q.front(); q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx>11 || ny < 0 || ny>5) continue;
			if (vis[nx][ny] || board[nx][ny] == '.' || board[nx][ny] != color) continue; //방문했거나, 색이 없거나, 색이 다르면 continue
			q.push({ nx,ny });
			tmp.push_back({ nx,ny });
			vis[nx][ny] = true;
		}
	}

	if (tmp.size() >= 4) {
		isPuyo = true;
		for (auto cur : tmp) {
			board[cur.X][cur.Y] = '.';
		}
	}

}


int main() {

	FIO;

	for (int i = 0; i < 12; i++) cin >> board[i];

	do {
		isPuyo = false;

		//빈칸 아래로 내리는 작업 필요
		for (int i = 0; i < 6; i++) {
			for (int j = 10; j >= 0; j--) {
				int tmp = j;
				while (tmp < 11 && board[tmp + 1][i] == '.') {
					swap(board[tmp][i], board[tmp + 1][i]);
					tmp++;
				}
			}
		}

		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				if (!vis[i][j] && board[i][j] != '.') //방문한적 없고 빈칸이 아니면 해당 위치 뿌요 함수로 넘김
					puyo(i, j);
			}
		}
		
		if (isPuyo) ans++;
		resetVis();

	} while (isPuyo); //뿌요 터졌으면 다시 반복

	cout << ans;

	return 0;
}