#include<cstdio>
#include<algorithm>
using namespace std;
int p[300000];
bool visit[300000];
int find(int u) {
	if (p[u] == u) return u;
	return p[u] = find(p[u]);
}
void merge(int u, int v) {
	u = find(u); v = find(v);
	if (u == v) return;
	p[u] = v;
}
int main() {
	int n, m;
	scanf("%d %d", &m, &n);
	for (int i = 1; i <= n; i++) p[i] = i;
	for (int i = 1; i <= m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		if (!visit[u]) {
			visit[u] = true;
			merge(u, v);
		}
		else if (!visit[v]) {
			visit[v] = true;
			merge(v, u);
		}
		else if (!visit[find(u)]) {
			visit[find(u)] = true;
			merge(u, v);
		}
		else if (!visit[find(v)]) {
			visit[find(v)] = true;
			merge(v, u);
		}
		else {
			puts("SMECE");
			continue;
		}
		puts("LADICA");
	}
	return 0;
}