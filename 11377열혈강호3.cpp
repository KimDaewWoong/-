#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
int n, m, k, b[1001];
bool vt[1001];
vector<vector<int>> a;
int dfs(int here) {
	if (vt[here]) return 0;
	vt[here] = 1;
	for (int i = 0; i < a[here].size(); i++) {
		int there = a[here][i];
		if (!b[there] || dfs(b[there])) {
			b[there] = here;
			return 1;
		}
	}
	return 0;
}
int func() {
	int result = 0;
	for (int i = 1; i <= n; i++) {
		memset(vt, false, sizeof(vt));
		if (dfs(i)) result++;
	}
	for (int i = 1; i <= n && k > 0; i++) {
		memset(vt, false, sizeof(vt));
		if (dfs(i)) {
			result++;
			k--;
		}
	}
	return result;
}
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d%d%d", &n, &m, &k);
	a.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		int k, z = 0;
		scanf("%d", &k);
		while (k--) {
			scanf("%d", &z);
			a[i].push_back(z);
		}
	}
	printf("%d", func());
	return 0;
}