#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int n, m, dy[100010][25], lv[100010];
vector<int> g[100010];
bool b[100010];
void dfs(int node) {
	b[node] = true;
	for (int i = 0; i < g[node].size(); i++) {
		int u = g[node][i];
		if (b[u]) continue;
		lv[u] = lv[node] + 1;
		dy[u][0] = node;
		for (int j = 1; j <= 20; j++) {
			dy[u][j] = dy[dy[u][j - 1]][j - 1];
		}
		dfs(u);
	}
}
int lca(int a, int b) {
	if (lv[a] < lv[b]) swap(a, b);
	for (int i = 20; i >= 0; i--) {
		if ((1<<i) <= (lv[a] - lv[b])) {
			a = dy[a][i];
		}
	}
	if (a == b) return a;
	for (int i = 20; i >= 0; i--) {
		if (dy[a][i] != dy[b][i]) {
			a = dy[a][i];
			b = dy[b][i];
		}
	}
	return dy[a][0];

}
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		g[a].push_back(b);
		g[b].push_back(a);
	}
	lv[1] = 1;
	dfs(1);

	scanf("%d", &m);
	while (m--) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", lca(a, b));
	}
	return 0;
}