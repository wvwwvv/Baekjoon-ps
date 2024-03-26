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

    vector<int> brute(chicken.size(), 1); //벡터 선언할 때 크기와 초깃값 설정 
    fill(brute.begin(), brute.begin() + chicken.size() - M, 0); // 앞의 chicken.size() - M 칸은 0, 뒤의 M칸은 1
    //fill(시작주소, 끝주소, 값) 끝주소 - 시작주소의 크기만큼 fill한다. 윗줄에서는 chicken.size() - M 개만큼 0으로 초기화한다.
    int mn = 0x7f7f7f7f; // 답을 저장할 변수, int의 최댓값

    do { //do의 한번의 시행은 chicken.size()개수의 치킨집중 M개를 조합해 마을의 치킨거리를 구한다. 
        int dist = 0; // 도시의 치킨 거리를 저장할 변수
        for (auto h : house) {
            int tmp = 0x7f7f7f7f; // 집의 치킨 거리를 저장할 변수
            for (int i = 0; i < chicken.size(); i++) {
                if (brute[i] == 0) continue; //조합을 구현
                tmp = min(tmp, abs(chicken[i].X - h.X) + abs(chicken[i].Y - h.Y)); // 집의 치킨 거리 갱신
            }
            dist += tmp;
        }
        mn = min(mn, dist);
    } while (next_permutation(brute.begin(), brute.end()));

    cout << mn;

	return 0;
}