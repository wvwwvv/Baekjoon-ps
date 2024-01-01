#include <iostream>
#include <algorithm>
#include <queue>
#define X first
#define Y second
using namespace std;
#define FIO ios::sync_with_stdio(0), cin.tie(0)

//�� �࿡�� �� �ϳ��� ���� ������ �����ؾ���

int N; //N < 15
int ans = 0;

bool isused1[15]; // ����
bool isused2[30]; //�ϳ��� ����� �밢���� ���ϴ� (��,��)���� ��+���� �����ϴ� ex) (3,1)�� (2,2)�� ��+���� 4�̹Ƿ� ���� �밢���� ��ġ�� �ְ�
				  //isused[4]�� ���� ������ �ش� �밢���� ���� ���� ���θ� �Ǵ��Ѵ�
bool isused3[30]; //�ϳ��� ������ �밢���� ���ϴ� (��,��)���� ��-���� �����ϴ�

void func(int cur) { //cur: ���� ��
	 
	//���� ���ϴ� cur�� �̿��� �����ϹǷ� �� �� (����)�� �ٸ� ���� �����ϴ��� ���θ� �Ǵ��� �ʿ䰡 ������ ������
	//����(��), ����� �밢��, ������ �밢�� �� 3������ Ȯ���ϸ� ��

	if (cur == N) {	//��������
		ans++;
		return;
	}


	for (int i = 0; i < N; i++) { // i : ��
		if (isused1[i] || isused2[cur + i] || isused3[cur - i + N - 1]) continue; 

		isused1[i] = true;
		isused2[cur + i] = true;
		isused3[cur - i + N - 1] = true;
		func(cur + 1);
		isused1[i] = false;
		isused2[cur + i] = false;
		isused3[cur - i + N - 1] = false;


	}

}

int main() {

	FIO;

	cin >> N;

	func(0);

	cout << ans;

	return 0;
}
