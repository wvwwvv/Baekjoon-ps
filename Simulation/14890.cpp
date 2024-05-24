//BaaaarkingDog 코드 참고함
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

int N, L;
int board[101][101];

int checkLine(vector<int>& line) {
	int idx = 0; //line에서 한 점의 index
	int cnt = 1; //현재 보고있는(위치한) 높이가 같은 구간의 길이(평평해서 경사로를 놓을 수 있는 여지가 있는 곳)

	while (idx < N - 1) {
		if (abs(line[idx] - line[idx + 1]) > 1) return 0; //한번에 2이상 높이 차이나면 경사 못놓음

		if (line[idx] == line[idx + 1]) {
			idx++; //다음칸으로 이동
			cnt++; //현재 서 있는 평평한 땅 길이 1증가
		}
		else if (line[idx] < line[idx+1]) { //다음칸이 높으면
			if (cnt < L) return 0; //평평한 땅이 L보다 작으면 경사 못놓음

			cnt = 1; //경사 놓았으므로 현재 보고있는 평평한 땅 1로 초기화
			idx++;
		}
		else { //다음칸이 낮으면
			
			if (idx + L >= N) return 0; //뒤에 L만큼 경사를 놓을 공간이 없음, idx는 0부터 시작하므로 >=N이어야함
			for (int i = idx + 1; i < idx + L; i++) { //현재 보고있는 땅 뒤에 평평한 땅이 L이상인지 확인해야함
				if (line[i] != line[i + 1]) return 0;
			}
			idx += L;
			cnt = 0; //지금 보고있는 곳은 경사로가 설치된 끝 부분이므로 평평하지 않음.
		}
	}

	return 1;

}


int main() {

	FIO;
	
	cin >> N >> L;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];

	int ans = 0;


	for (int i = 0; i < N; i++) {//가로
		vector<int> line;
		for (int j = 0; j < N; j++) {
			line.push_back(board[i][j]);
		}
		ans += checkLine(line);
	}

	for (int i = 0; i < N; i++) {//세로
		vector<int> line;
		for (int j = 0; j < N; j++) {
			line.push_back(board[j][i]);
		}
		ans += checkLine(line);
	}

	cout << ans;

	return 0;
}