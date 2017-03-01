//MST
#include<cstdio>
#include<algorithm>
using namespace std;
int n, m, arr[10100], val[10100];
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
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		arr[i] = i;
		scanf("%d", &val[i+1]);
	}
	for (int i = 0; i < m; i++) {
		int q;
		scanf("%d %d %d", &e[i].u, &e[i].v, &q);
		e[i].w = q + q + val[e[i].u] + val[e[i].v];
	}
	sort(e, e + m, cmp);
	int result = 0;
	for (int i = 0; i < m; i++) {
		if (merge(e[i].u, e[i].v)) result += e[i].w;
	}
	sort(val, val + n);
	printf("%d\n", result + val[1]);
	return 0;
}