//union-find
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int n, m;
vector<int> parent, ranc;
int find(int u) {
	if (parent[u] == u) return u;
	else return parent[u] = find(parent[u]);
}
void merge(int u, int v) {
	u = find(u); v = find(v);
	if (u == v) return;

	if (ranc[u] > ranc[v]) swap(u, v);
	if (ranc[u] == ranc[v]) ranc[v]++;
	parent[u] = v;
	ranc[v] += ranc[u];
}
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &n, &m);
	parent.resize(n + 1);
	ranc.resize(n + 1, 1);
	for (int i = 1; i <= n; i++) parent[i] = i;
	for (int i = 1; i <= m; i++) {
		int a, u, v;
		scanf("%d %d %d", &a, &u, &v);
		if (a) {
			if (find(u)==find(v)) puts("YES");
			else puts("NO");
		}
		else merge(u, v);
	}

	return 0;
}