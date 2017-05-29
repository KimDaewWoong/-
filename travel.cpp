#include<cstdio>
#include<algorithm>
using namespace std;
int t, n, m, arr[10010];
struct Edge {
	int u, v, w;
}e[100010];
bool cmp(Edge a, Edge b) {
	return a.w < b.w;
}
int find(int u) {
	if (arr[u] == u) return u;
	return arr[u] = find(arr[u]);
}
bool merge(int u, int v) {
	u = find(u); v = find(v);
	if (u == v) return false;
	arr[u] = v;
	return true;
}
int main() {
	//freopen("input.txt", "r", stdin);
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++) arr[i] = i;
		for (int i = 0; i < m; i++)
			scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].w);

		sort(e, e + m, cmp);
		int result = 0;
		for (int i = 0; i < m; i++) {
			if (merge(e[i].u, e[i].v)) result += e[i].w;
		}
		printf("%d\n", result);
	}
	return 0;
}