#include <iostream>
#include <math.h>
#include <algorithm>
#include <queue>
using namespace std;
#define FIO ios::sync_with_stdio(0), cin.tie(0);
#define X first
#define Y second

int dx[4] = { 1,0,-1,0 }; //������� ��, ��, ��, ��
int dy[4] = { 0,1,0,-1 };

int N, M;
int board1[10][10];
int board2[10][10];
vector<pair<int, int>> cctv; //cctv ��ǥ ����


bool OOB(int x, int y) { // out of bounds üũ, �̷� ����� �͵� �Լ��� ����� ���°��� ��
	return x < 0 || y < 0 || x >= N || y >= M;
}

void go_dir(int x, int y, int dir) { // dir �������� cctv ����, dir��  0:��, 1:��, 2:��, 3:��
	dir = dir % 4;

	while (1) {
		x += dx[dir];
		y += dy[dir];
		if (OOB(x, y) || board2[x][y] == 6) return; //������ ����ų� ���� ������ ����
		if (board2[x][y] != 0) continue; // �ش� ĭ�� ��ĭ�� �ƴϸ� continue
		board2[x][y] = 7; //���� ���� ������ 7�� ����
	}
}


int main() {

	FIO;

	cin >> N >> M;

	int mn = 0; //�簢���� ũ��

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board1[i][j];
			if (board1[i][j] != 0 && board1[i][j] != 6)
				cctv.push_back({ i,j });
			if (board1[i][j] == 0)
				mn++;
		}
	}

	// cctv�� ������ ���� 4���̸�, 4�� 4������ŭ �ݺ��ؾ��� -> ��� ���⿡ ���� ����Ǽ��� Ȯ���ϱ� ����, �ߺ��Ǵ� ��Ȳ���� ��� ���°��� ��

	int c_size = cctv.size();
	int iter = 1;

	for (int i = 0; i < c_size; i++)
		iter = iter * 4;

	for (int temp = 0; temp < iter; temp++) { //��� ����� �� �� �ȱ�

		for (int i = 0; i < N; i++) //�� temp���� ���� �ٸ� ����(���� �ٸ� �簢������ ũ�⸦ ����)�̹Ƿ� board2�� �Ź� �����Ѵ�.
			for (int j = 0; j < M; j++)
				board2[i][j] = board1[i][j];

		//�ſ� �߿�!!
		//temp�� (0) ~ (4�� �ŵ����� - 1) ������ ���̹Ƿ� 4�������� ��Ÿ�� �� ������ ���� ū �ڸ����� c_size�� ����.
		//��, temp�� �� �ڸ����� ������ cctv�� ����Ű�� �����̶�� ������ �� �ִ�.
		//���� ���, temp % 4�� ���� ù��° cctv�� ����Ű�� �����̴�. (temp/4) % 4 �� �ι�° cctv�� ����Ű�� �����̴�.

		int num = temp;

		for (int i = 0; i < c_size; i++) {
			int dir = num % 4; //ù for������ dir�� �ǹ��ϴ� �� : ù��° cctv�� ����Ű�� ����
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
		} //��� cctv�� ���⿡ ���� �Ⱦ� �簢���밡 ������

		int val = 0;

		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				if (board2[i][j] == 0)
					val++;

		mn = min(mn, val); //iter���� mn �ּڰ� ����

	} // iter��ŭ�� �ݺ� ��

	cout << mn;

}
