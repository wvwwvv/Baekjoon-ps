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

int N, M;
int board[51][51];
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;

int main() {

	FIO;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1) house.push_back({ i,j });
			if (board[i][j] == 2) chicken.push_back({ i,j });
		}
	}

    vector<int> brute(chicken.size(), 1); //���� ������ �� ũ��� �ʱ갪 ���� 
    fill(brute.begin(), brute.begin() + chicken.size() - M, 0); // ���� chicken.size() - M ĭ�� 0, ���� Mĭ�� 1
    //fill(�����ּ�, ���ּ�, ��) ���ּ� - �����ּ��� ũ�⸸ŭ fill�Ѵ�. ���ٿ����� chicken.size() - M ����ŭ 0���� �ʱ�ȭ�Ѵ�.
    int mn = 0x7f7f7f7f; // ���� ������ ����, int�� �ִ�

    do { //do�� �ѹ��� ������ chicken.size()������ ġŲ���� M���� ������ ������ ġŲ�Ÿ��� ���Ѵ�. 
        int dist = 0; // ������ ġŲ �Ÿ��� ������ ����
        for (auto h : house) {
            int tmp = 0x7f7f7f7f; // ���� ġŲ �Ÿ��� ������ ����
            for (int i = 0; i < chicken.size(); i++) {
                if (brute[i] == 0) continue; //������ ����
                tmp = min(tmp, abs(chicken[i].X - h.X) + abs(chicken[i].Y - h.Y)); // ���� ġŲ �Ÿ� ����
            }
            dist += tmp;
        }
        mn = min(mn, dist);
    } while (next_permutation(brute.begin(), brute.end()));

    cout << mn;

	return 0;
}