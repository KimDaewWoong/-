#include<iostream>
#include<string>
#include<cstdio>
#include <algorithm>

using namespace std;

string n, m;
int a;
char c[27];
int main() {
	freopen("input.txt", "r", stdin);
	cin >> n;
	for (int i = 0; i < n.length(); i++) {
		a = n[i] - 'A';
		c[a]++;
	}

	return 0;
}


//¦������ Ȧ������ Ȯ�� Ȧ���ϰ�� �ѹ��ڸ� Ȧ��������
//��¥���� �������� �����ؼ� �ٿ��ְ� ���