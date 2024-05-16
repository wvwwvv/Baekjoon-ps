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

int dx[4] = { -1,0,1,0 }; //��, ��, ��, ��
int dy[4] = { 0,1,0,-1 };

int N, K, L; //�� ��, ��� ����, ���� ��ȯ
int board[101][101]; //1��� 2��
int dir = 1; //�ʱ� ���� ��
int ans = 0;
deque <pair<int, int>> snake;
queue<pair<int, char>> changDir; //L�� D����

int main() {

	FIO;

	cin >> N >> K;

	while (K--) { //���
		int x, y;
		cin >> x >> y;
		board[x][y] = 1;
	}

	cin >> L;

	while (L--) { //������ȯ
		int a;
		char b;
		cin >> a >> b;
		changDir.push({ a,b });
	}

	snake.push_front({ 1,1 }); //���� ó�� ��ġ

	while (true) {
		
		auto cur = snake.front();

		board[cur.X][cur.Y] = 2; //���� �Ӹ� �̵�
		ans++;

		int nx = cur.X + dx[dir];
		int ny = cur.Y + dy[dir];

		if (nx<1 || nx>N || ny<1 || ny>N || board[nx][ny] == 2) break;

		//��� ������ tail �ǵ� �ʿ����

		//��� ������
		if (board[nx][ny] != 1) {
			auto tail = snake.back();
			board[tail.X][tail.Y] = 0; //������ �پ�� 
			snake.pop_back();
		}

		//���⼭ ans����ŭ �ð��� ������ ��

		auto cmd = changDir.front();

		if (cmd.X == ans) {
			if (cmd.Y == 'L') dir += 3; //�������� 90�� ȸ��(�ݽð�)
			else dir += 1; //�ð�
			changDir.pop();
			dir %= 4;
		}

		snake.push_front({ nx,ny });
	}

	cout << ans;

	return 0;
}