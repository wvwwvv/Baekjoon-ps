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

void go(int x, int dir) { //x: (x+1) ���, dir : ����
	int dirs[4] = {}; //�� ����� ȸ�� ���� 1,0,-1
	dirs[x] = dir;

	int idx = x;
	//�������� ȸ�� ����
	while (idx > 0 && wheel[idx][6] != wheel[idx - 1][2]) { //���� ��Ͽ� ���� ��ϰ� ��� ���� �ٸ���
		dirs[idx - 1] = -dirs[idx];
		idx--;
	}

	idx = x;
	//���������� ȸ�� ����
	while (idx < 3 && wheel[idx][2] != wheel[idx + 1][6]) {
		dirs[idx + 1] = -dirs[idx];
		idx++;
	}

	for (int i = 0; i < 4; i++) {
		if (dirs[i] == -1) { //�ݽð�, ���� �� �ڷ�
			rotate(wheel[i].begin(), wheel[i].begin() + 1, wheel[i].end()); //�������� 1ĭ �̵�
		}
		else if (dirs[i] == 1) {
			rotate(wheel[i].begin(), wheel[i].begin() + 7, wheel[i].end()); //�������� 7ĭ �̵� (-1ĭ �̵�)
		}
	}

}


int main() {

	FIO;

	//�ð���� : ���� ������
	//�ݽð���� : ���� ������

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