#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int t, n, m, cnt, xv, yv, tv;
int pan[110], x[10], y[10];
string a, b, temp;
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &t);
	while (t--) {
		cnt = 0; a = ""; b = "";
		scanf("%d %d", &n, &m);
		for (int i = 0; i < m; i++) { 
			scanf("%d", &x[i]);
			a += x[i] + '0';
		}
		xv = atoi(a.c_str());
		for (int i = 0; i < m; i++) {
			scanf("%d", &y[i]);
			b += y[i] + '0';
		}
		yv = atoi(b.c_str());
		for (int i = 0; i < n; i++) scanf("%d", &pan[i]);
		for (int i = 0; i < n; i++) {
			if (x[0] > pan[i] || y[0] < pan[i]) continue;
			for (int j = i; j < i+m; j++) temp += pan[j%n] + '0';
			tv = atoi(temp.c_str());
			if (xv <= tv && tv <= yv) cnt++;
			temp = "";
		}
		printf("%d\n", cnt);
	}
	return 0;
}