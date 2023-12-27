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

int M, N, K; // 행, 열
int board[101][101];
bool vis[101][101];

int func() {

	cin >> M >> N >> K; //문제에서 (7,5)는 5행 7열을 의미

	vector <pair<int, int>> s_point;
	vector <pair<int, int>> e_point;


	for (int i = 0; i < K; i++) {
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		s_point.push_back({ x1,y1 });
		e_point.push_back({ x2,y2 });
	}

	for (int i = 0; i < s_point.size(); i++) {
		int x1, x2, y1, y2;
		x1 = s_point[i].X;
		y1 = s_point[i].Y;
		x2 = e_point[i].X;
		y2 = e_point[i].Y;

		for (int a = y1; a < y2; a++) { //문제 특성상 행과 열이 반대임
			for (int b = x1; b < x2; b++) {
				board[a][b] = 1;
			}
		}
	}

	//이제 BFS 시작

	queue<pair<int, int>> Q;

	int num = 0;
	vector<int> area;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] == 1 || vis[i][j]) continue;
			int cnt = 0;

			num++;
			Q.push({ i,j });
			vis[i][j] = true;

			while (!Q.empty()) {
				cnt++;
				auto cur = Q.front(); Q.pop();

				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];
					if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
					if (board[nx][ny] == 1 || vis[nx][ny]) continue;
					vis[nx][ny] = true;
					Q.push({ nx,ny });
				}
			}

			area.push_back(cnt);

		}
	}


	sort(area.begin(), area.end());

	cout << num << '\n';
	for (auto ans : area)
		cout << ans << ' ';
	
	

	return 0;
}


int main() {
	
	FIO;

	func();

	
	return 0;
}