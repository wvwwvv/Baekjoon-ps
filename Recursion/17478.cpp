#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
#define FIO ios::sync_with_stdio(0), cin.tie(0)
#define X first
#define Y second

int N;

string bar = "____";

int func(int recur) { 
	
	for (int i = 0; i < recur; i++) cout << bar;
	cout << "\"����Լ��� ������?\"\n";

	if (recur == N) {
		for (int i = 0; i < recur; i++) cout << bar;
		cout << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n";
		for (int i = 0; i < recur; i++) cout << bar;
		cout << "��� �亯�Ͽ���.\n";
		return 0;
	}

	
	for (int i = 0; i < recur; i++) cout << bar;
	cout << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n";
	for (int i = 0; i < recur; i++) cout << bar;
	cout << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n";
	for (int i = 0; i < recur; i++) cout << bar;
	cout << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n";

	func(recur+1);
	
	for (int i = 0; i < recur; i++) cout << bar;
	cout << "��� �亯�Ͽ���.\n";

	return 0;

}


int main() {

	FIO;

	cin >> N;
	
	cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";

	func(0);

	return 0;
}