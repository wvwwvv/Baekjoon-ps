//�� ĭ�� �Ʒ��� ������ ���, puyo �Լ� ������ bfs�� ������ ������ vector Ÿ���� tmp�� �ش� ��ġ ���� -> 4���̻� ���� ������ �� ��ġ ��� .�� ����
//bfs ������ ��ġ ��� -> .�� �ƴϰ�, �湮�� �� ���� ��

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

bool isPuyo; //�ѿ� ��������
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
	vector<pair<int, int>> tmp; // 4�� �̻� �پ������� ������ ��ġ ����
	q.push({ x,y });
	tmp.push_back({ x,y });

	while (!q.empty()) {
		auto cur = q.front(); q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx>11 || ny < 0 || ny>5) continue;
			if (vis[nx][ny] || board[nx][ny] == '.' || board[nx][ny] != color) continue; //�湮�߰ų�, ���� ���ų�, ���� �ٸ��� continue
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

		//��ĭ �Ʒ��� ������ �۾� �ʿ�
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
				if (!vis[i][j] && board[i][j] != '.') //�湮���� ���� ��ĭ�� �ƴϸ� �ش� ��ġ �ѿ� �Լ��� �ѱ�
					puyo(i, j);
			}
		}
		
		if (isPuyo) ans++;
		resetVis();

	} while (isPuyo); //�ѿ� �������� �ٽ� �ݺ�

	cout << ans;

	return 0;
}