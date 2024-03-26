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

int n, w, L;
int cnt = 0; //���� ��
int weight = 0; //�ٸ� ����
queue<int> q; //�ٸ� ���� ���� ���� Ʈ���� ����
vector<pair<int, int>> v; //�ٸ� ���� �ִ� Ʈ���� ����, ��ġ ����. ex) w==2�� �ٸ����� ��ġ���� 0,1�� ��� �ٸ� ���� �ִ�.

int main() {

	FIO;

	cin >> n >> w >> L;

	while (n--) {
		int a;
		cin >> a;
		q.push(a);
	}

	do {
		for (int i = 0; i < v.size(); i++) { //�ٸ� �� Ʈ���� ��ĭ ����
			v[i].Y += 1;
		}

		for (int i = 0; i < v.size(); i++) {
			if (v[i].Y >= w)
				v[i].X = 0; //�������� Ʈ���� ���� 0���� ����
		}

		if (!v.empty()) {
			weight = 0;
			for (int i = 0; i < v.size(); i++) //�ٸ� �� ���� ����
				weight += v[i].X;
		}
		
		if (q.front() <= L - weight) { //�ٸ��� Ʈ���� �ٸ��� �ö� �� ������
			int tmp = q.front(); q.pop();
			v.push_back({ tmp, 0 }); //�� Ʈ���� v���Ϳ� ����
		}

		cnt++;
			
	} while (!q.empty());

	//�ٸ����� ������ Ʈ���� �ö� ����, �� Ʈ���� �������� ���� : w
	cnt += w;

	cout << cnt;

	return 0;
}