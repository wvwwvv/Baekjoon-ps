#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
#define FIO ios::sync_with_stdio(0), cin.tie(0)


// a^2n % b ���ϱ�		=>     { (a^n % b) X (a^n % b) } % b �̿�

using ll = long long;

ll func(ll A, ll B, ll C) { //B�� ��� 2�� �����鼭 ��� ��

	if (B == 1) return A % C; //��������

	ll val = func(A, B / 2, C);
	val = (val * val) % C;
	if (B % 2 == 1) {
		return (val * A) % C;
	}
	else {
		return val;
	}

}


int main() {

	FIO;
	ll A, B, C;
	cin >> A >> B >> C;
	
	
	ll ans = func(A,B,C);
	cout << ans;

	return 0;
}