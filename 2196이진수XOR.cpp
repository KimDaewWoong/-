//bfs
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<queue>
using namespace std;
int n, m;
int b[20][110];
int main() {
	freopen("input.txt", "r", stdin);
	memset(b, -1, sizeof(b));
	scanf("%d %d", &n, &m);
	string a;
	for (int i = 0; i <= m; i++) {
		cin >> a;
		for (int j = 0; j < n; j++) {
			b[i][j] = a[j]-'0';
		}
	}


	return 0;
}