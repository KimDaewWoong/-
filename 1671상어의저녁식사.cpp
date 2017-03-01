#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
int n, b[1001];
bool visited[1001];
pair<pair<int, int>, int> pa[1010];
vector<vector<int>> vt;
int dfs(int here) {
	if (visited[here]) return 0;
	visited[here] = 1;
	for (int i = 0; i < vt[here].size(); i++) {
		int there = vt[here][i];
		if (!b[there] || dfs(b[there])) {
			b[there] = here;
			return 1;
		}
	}
	return 0;
}
int func() {
	int ret = 0;
	for (int i = 1; i <= n; i++) {
		int j = 2;
		while (j--) {
			memset(visited, false, sizeof(visited));
			if (dfs(i)) ret++;
		}
	}
	return ret;
}
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	vt.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		pa[i].first.first = a;
		pa[i].first.second = b;
		pa[i].second = c;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			if (pa[i].first.first == pa[j].first.first && pa[i].first.second == pa[j].first.second && pa[i].second == pa[j].second) {
				if (i < j) {
					vt[i].push_back(j);
				}
			}
			else if (pa[i].first.first >= pa[j].first.first && pa[i].first.second >= pa[j].first.second && pa[i].second >= pa[j].second) {
				vt[i].push_back(j);
			}
		}
	}
	printf("%d", n - func());

	return 0;
}