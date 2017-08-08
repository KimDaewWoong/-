#include<cstdio>
#include<algorithm>
using namespace std;
int p[220], ranc[220];
int find(int u) {
	if (p[u] == u) return u;
	return p[u] = find(p[u]);
}
void merge(int u, int v) {
	u = find(u); v = find(v);
	if (u == v) return;
	if (ranc[u] > ranc[v]) swap(u, v);
	if (ranc[u] == ranc[v]) ranc[v]++;
	ranc[v] += ranc[u];
	p[u] = v;
}
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		p[i] = i;
		ranc[i] = 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int a;
			scanf("%d", &a);
			if (a) merge(i, j);
		}
	}
	bool flag = false;
	int now;
	scanf("%d", &now);
	for (int i = 1; i < m; i++) {
		int next;
		scanf("%d", &next);
		if (find(now) != find(next)) {
			flag = true;
			break;
		}
		now = next;
	}
	if (flag) puts("NO");
	else puts("YES");
	return 0;
}