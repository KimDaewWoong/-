#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
int n, m, u, v, V[510], bMatch[510];
vector<vector<int>> node;
int dfs(int here) {
	if (V[here]) {
		return 0;
	}
	V[here] = 1;
	for (int there : node[here]) {
		if (!bMatch[there] || dfs(bMatch[there])) {
			bMatch[there] = here;
			return 1;
		}
	}
	return 0;
}

int main() {
	scanf("%d %d", &n, &m);
	node.resize(n + 1);
	while (m--) {
		scanf("%d %d", &u, &v);
		node[u].push_back(v);
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		memset(V, 0, sizeof(V));
		if (dfs(i)) {
			++ans;
		}
	}
	printf("%d\n", ans);
}