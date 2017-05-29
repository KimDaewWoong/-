#include<cstdio>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
int n, p[1050];
vector<vector<int>> vt;
priority_queue<pair<int, pair<int, int>>>pq;
int find(int a) {
	if (a == p[a]) return a;
	return p[a] = find(p[a]);
}
void marge(int u, int v) {
	u = find(u); v = find(v);
	if (u == v) return;
	if (u > v) swap(u, v);
	p[u] = v;
}
int main() {
	scanf("%d", &n);
	vt.resize(n + 1);
	for (int i = 1; i <= n; i++) p[i] = i;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			int val;
			scanf("%d", &val);
			pq.push({ -val,{ i, j } });
		}
	}
	int t = n - 1;
	while (t) {
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		pq.pop();
		if (find(x) == find(y)) continue;
		vt[x].push_back(y);
		vt[y].push_back(x);
		marge(x, y);
		t--;
	}
	for (int i = 1; i <= n; i++)
		sort(vt[i].begin(), vt[i].end());

	for (int i = 1; i <= n; i++) {
		printf("%d ", vt[i].size());
		for (int j = 0; j < vt[i].size(); j++)
			printf("%d ", vt[i][j]);
		puts("");
	}
	return 0;
}