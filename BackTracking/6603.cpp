#include <iostream>
#include <algorithm>
#include <queue>
#define X first
#define Y second
using namespace std;
#define FIO ios::sync_with_stdio(0), cin.tie(0)


int k;
int S[15];
int subArr[15];

void func() { 
	
	
}

int main() {

	FIO;


	while (true) {

		cin >> k;

		if (k == 0) return 0;

		for (int i = 0; i < k; i++) cin >> S[i];

		for (int i = 0; i < k; i++) subArr[i] = 1;

		for (int i = 0; i < 6; i++) subArr[i] = 0;

		do {

			for (int i = 0; i < k; i++) {
				if (subArr[i] == 0) {
					cout << S[i] << ' ';
				}
			}
			cout << '\n';

		} while (next_permutation(subArr, subArr + k));

		cout << '\n';
	}

	return 0;
}
