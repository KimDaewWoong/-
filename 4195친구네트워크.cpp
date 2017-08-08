#include<cstdio>
#include<algorithm>
#include<iostream>
#include<string>
#include<cstring>
#include<map>
using namespace std;
int p[200010], ranc[200010];
int find(int u) {
	if (p[u] == u) return u;
	return p[u] = find(p[u]);
}
void merge(int u, int v) {
	u = find(u); v = find(v);
	if (u == v) return;
	ranc[v] += ranc[u];
	p[u] = v;
}
int main() {
	int t, f;
	scanf("%d", &t);
	while (t--) {
		memset(p, 0, sizeof(p));
		scanf("%d", &f);
		for (int i = 0; i < 2 * f; i++) {
			p[i] = i;
			ranc[i] = 1;
		}
		map<string, int> mp;
		int idx = 0;
		for (int i = 0; i < f; i++) {
			char a[25], b[25];
			scanf("%s %s", a, b);
			if (!mp.count(a)) mp[a] = idx++;
			int u = mp[a];
			if (!mp.count(b)) mp[b] = idx++;
			int v = mp[b];
			merge(u, v);
			printf("%d\n", ranc[p[v]]);
		}
	}
	return 0;
}