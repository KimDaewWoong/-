#include<iostream>
#include<cstdio>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
int n, m;
char s[26];
map <int, string> is;
map <string, int> si;
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%s", &s);
		is[i] = s;
		si[s] = i;
	}
	for (int i = 1; i <= m; i++) {
		scanf("%s", &s);
		if (s[0] >= '0' && s[0] <= '9')
			cout << is[stoi(s)] << endl;
		else printf("%d\n", si[s]);
	}

	return 0;
}