#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
int T, N, M, a, b, w;
vector<vector<pair<int, int>>> vt;
bool visited[1010];
int func(int v) {
	visited[v] = true;
	if (vt[v].size() == 1 && v != 1) return 987654321;
	int ret = 0;
	for (int i = 0; i < vt[v].size(); i++) {
		int nv = vt[v][i].first;
		if (!visited[nv]) ret += min(func(nv), vt[v][i].second);
	}
	return ret;
}
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &N, &M);
		vt.resize(N + 1);
		memset(visited, false, sizeof(visited));
		while (M--) {
			scanf("%d %d %d", &a, &b, &w);
			vt[a].push_back({ b,w });
			vt[b].push_back({ a,w });
		}
		printf("%d\n", func(1));
		vt.clear();
	}
	return 0;
}