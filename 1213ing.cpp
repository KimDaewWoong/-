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


//짝수인지 홀수인지 확인 홀수일경우 한문자만 홀수여야함
//반짜른거 역순으로 복사해서 붙여넣고 출력