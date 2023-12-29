#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
#define FIO ios::sync_with_stdio(0), cin.tie(0)
#define X first
#define Y second

int N, r, c; // N<=15 ÇÑ º¯ 2^N

int func(int n, int r, int c) { 
	
	if (n == 0) return 0;
	
	int half = pow(2, n - 1);

	if (r < half && c < half) return func(n - 1, r, c);
	if (r < half && c >= half) return half * half + func(n - 1, r, c - half);
	if (r >= half && c < half) return 2 * half * half + func(n - 1, r - half, c);
	if (r >= half && c >= half) return 3 * half * half + func(n - 1, r - half, c - half);
}


int main() {

	FIO;
	
	cin >> N >> r >> c;
	cout << func(N, r, c);

	return 0;
}