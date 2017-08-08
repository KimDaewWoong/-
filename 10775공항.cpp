#include<cstdio>
#include<algorithm>
using namespace std;
int p[100000];
int find(int u) {
	if (p[u] == u) return u;
	return p[u] = find(p[u]);
}
void merge(int u, int v) {
	u = find(u); v = find(v);
	p[u] = v;
}
int main() {
	int n, m, g, cnt = 0;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) p[i] = i;
	for (int i = 1; i <= m; i++) {
		scanf("%d", &g);
		int u = find(g);
		if (u) {
			merge(u, u - 1);
			cnt++;
		}
		else break;
	}
	printf("%d\n", cnt);

	return 0;
}
