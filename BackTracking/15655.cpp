#include <iostream>
#include <algorithm>
#include <queue>
#define X first
#define Y second
using namespace std;
#define FIO ios::sync_with_stdio(0), cin.tie(0)


int N, M; 
int inputN[10]; //입력 수열
int subArr[10];

void func() { 
	
}

int main() {

	FIO;

	cin >> N >> M;

	for (int i = 0; i < N; i++) subArr[i] = 1;
	for (int i = 0; i < M; i++) subArr[i] = 0;

	for (int i = 0; i < N; i++) cin >> inputN[i];
	
	sort(inputN, inputN + N);
	
	do {
		for (int i = 0; i < N; i++) {
			if (subArr[i] == 0) {
				cout << inputN[i] << ' ';
			}
		}
		cout << '\n';
	} while (next_permutation(subArr, subArr + N));
	

	return 0;
}
