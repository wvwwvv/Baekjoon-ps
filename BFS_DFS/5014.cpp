#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <tuple>
#define FIO ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0)
#define X first
#define Y second
using namespace std;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int F, S, G, U, D;
int kangho[1000002];

int func() {

	
	cin >> F >> S >> G >> U >> D;

	for (int i = 0; i < 1000002; i++) kangho[i] = -1;

	kangho[S] = 0;

	queue<int> Q;
	Q.push(S);

	while (!Q.empty()) {
		auto cur = Q.front(); Q.pop();

		for (int nxt : {cur + U, cur - D}) {
			if (nxt > F || nxt < 1) continue;
			if (kangho[nxt] != -1) continue;
			kangho[nxt] = kangho[cur] + 1;
			Q.push(nxt);
		}
	}

	if (kangho[G] == -1) {
		cout << "use the stairs";
	}
	else {
		cout << kangho[G];
	}


	return 0;
}


int main() {
	
	FIO;

	func();

	
	return 0;
}