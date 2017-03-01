#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
string a;
char b[100];
int L, C, q, p;

int F(int, int, string, int ,int);
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &L, &C);
	for (int i = 0; i < C; i++) {
		cin >> b[i];
	}
	sort(b, b + C);
	cout << b;

	for (int i = 0; i < L; i++) {
		F(C, L, a, q, p);
	}


	return 0;
}
vector<string> pass;
int F(int cur, int length, string w, int q, int p) {
	if (cur > C) return;
	if (length == L) {
		if ()
			pass.push_back(w);
	}
	F(cur + 1, length + 1, w + b[cur], q + 1, p);
	F(cur + 1, length + 1, w + b[cur], q, p+1);
	F(cur + 1, length, w , q, p);
}

/*func(int cur, int length, string a, int q, int p)
	if(cur>C) return ;
	if(length==L){
		모음과 자음개수가 맞는지 check
}*/