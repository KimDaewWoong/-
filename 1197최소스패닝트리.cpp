#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int p[10010];
vector<pair<int, pair<int, int>>> vt;
int find(int u) {
	if (u == p[u]) return u;
	return p[u] = find(p[u]);
}
bool merge(int u, int v) {
	u = find(u); v = find(v);
	if (u == v) return false;
	p[u] = v;
	return true;
}
int main() {
	int v, e;
	scanf("%d %d", &v, &e);
	vt.resize(v + 1);
	for (int i = 0; i <= v; i++) p[i] = i;
	for (int i = 0; i < e; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		vt.push_back({ w,{ u, v } });
	}
	sort(vt.begin(), vt.end());
	int res = 0;
	for (int i = 0; i < vt.size(); i++) {
		if (merge(vt[i].second.first, vt[i].second.second))
			res += vt[i].first;
	}
	printf("%d\n", res);

	return 0;
}