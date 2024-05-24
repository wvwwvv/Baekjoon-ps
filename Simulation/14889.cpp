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

int N;
int board[22][22];

int main() {

	FIO;
	
	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];

	vector<int> brute(N); //초기값 (0,0,...,1,1)으로 설정

	fill(brute.begin(), brute.end(), 1);
	fill(brute.begin(), brute.begin() + N/2, 0); //0: a팀

	int m;
	bool flag = true;

	do {
		vector<int> a;
		vector<int> b;
		int sum_a = 0;
	    int sum_b = 0;

		for (int i = 0; i < N; i++) {
			if (brute[i] == 0) a.push_back(i);
			else b.push_back(i);
		}

		for (int i = 0; i < N / 2; i++) {
			for (int j = 0; j < N / 2; j++) {
				if (i == j) continue;

				sum_a += board[a[i]][a[j]];
				sum_b += board[b[i]][b[j]];
			}
		}

		int val = abs(sum_a - sum_b);

		if (flag) {
			m = val;
			flag = false;
		}
	

		m = min(m, val);

	} while (next_permutation(brute.begin(), brute.end()));

	cout << m;
	

	return 0;
}