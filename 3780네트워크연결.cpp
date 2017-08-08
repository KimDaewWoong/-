#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int t, n, root, dist[20010], p[20010];
char c;

int find(int u) {
	if (u == p[u]) {
		root = u;
		return u;
	}
	int v = find(p[u]);
	dist[u] += dist[v];
	p[u] = root;

	return u;
}
void merge(int u, int v) {
	p[u] = v;
	dist[u] = abs(u - v) % 1000;
}
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &t);
	while (t--) {
		memset(p, 0, sizeof(p));
		memset(dist, 0, sizeof(dist));
		scanf("%d", &n);
		for (int i = 0; i <= n; i++) p[i] = i;
		while (scanf(" %c", &c)) {
			if (c == 'O') break;
			else if (c == 'E') {
				int u;
				scanf("%d", &u);
				find(u);
				printf("%d\n", dist[u]);
			}
			else {
				int u, v;
				scanf("%d %d", &u, &v);
				merge(u, v);
			}
		}
	}
	return 0;
}