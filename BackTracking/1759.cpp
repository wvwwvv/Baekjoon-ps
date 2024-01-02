#include <iostream>
#include <algorithm>
#include <queue>
#define X first
#define Y second
using namespace std;
#define FIO ios::sync_with_stdio(0), cin.tie(0)

int L, C; // L,C 는 3이상 15이하 L : 암호의 길이 C : 암호에 사용될 알파벳의 개수
char inputC[20];
char outputC[20];

bool AEIOU(char ch) {
	return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

void func(int cur, int start) { 
	
	if (cur == L) {
		int cnt1 = 0; //aeiou
		int cnt2 = 0;

		for (int i = 0; i < L; i++) {
			if (AEIOU(outputC[i])) cnt1++;
			else cnt2++;
		}

		if (cnt1 >= 1 && cnt2 >= 2) {
			for (int i = 0; i < L; i++) {
				cout << outputC[i];
			}
			cout << '\n';
		}

		return;
	}

	for (int i = start; i < C; i++) {
		outputC[cur] = inputC[i];
		func(cur + 1, i + 1);
	}
	
}

int main() {

	FIO;

	cin >> L >> C;

	for (int i = 0; i < C; i++) cin >> inputC[i];

	sort(inputC, inputC + C);

	func(0,0);



	return 0;
}
