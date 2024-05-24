//BaaaarkingDog �ڵ� ������
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

int N, L;
int board[101][101];

int checkLine(vector<int>& line) {
	int idx = 0; //line���� �� ���� index
	int cnt = 1; //���� �����ִ�(��ġ��) ���̰� ���� ������ ����(�����ؼ� ���θ� ���� �� �ִ� ������ �ִ� ��)

	while (idx < N - 1) {
		if (abs(line[idx] - line[idx + 1]) > 1) return 0; //�ѹ��� 2�̻� ���� ���̳��� ��� ������

		if (line[idx] == line[idx + 1]) {
			idx++; //����ĭ���� �̵�
			cnt++; //���� �� �ִ� ������ �� ���� 1����
		}
		else if (line[idx] < line[idx+1]) { //����ĭ�� ������
			if (cnt < L) return 0; //������ ���� L���� ������ ��� ������

			cnt = 1; //��� �������Ƿ� ���� �����ִ� ������ �� 1�� �ʱ�ȭ
			idx++;
		}
		else { //����ĭ�� ������
			
			if (idx + L >= N) return 0; //�ڿ� L��ŭ ��縦 ���� ������ ����, idx�� 0���� �����ϹǷ� >=N�̾����
			for (int i = idx + 1; i < idx + L; i++) { //���� �����ִ� �� �ڿ� ������ ���� L�̻����� Ȯ���ؾ���
				if (line[i] != line[i + 1]) return 0;
			}
			idx += L;
			cnt = 0; //���� �����ִ� ���� ���ΰ� ��ġ�� �� �κ��̹Ƿ� �������� ����.
		}
	}

	return 1;

}


int main() {

	FIO;
	
	cin >> N >> L;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];

	int ans = 0;


	for (int i = 0; i < N; i++) {//����
		vector<int> line;
		for (int j = 0; j < N; j++) {
			line.push_back(board[i][j]);
		}
		ans += checkLine(line);
	}

	for (int i = 0; i < N; i++) {//����
		vector<int> line;
		for (int j = 0; j < N; j++) {
			line.push_back(board[j][i]);
		}
		ans += checkLine(line);
	}

	cout << ans;

	return 0;
}