#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#define INF 0x3F3F3F3F
using namespace std;
int n, m, f, g, dist[1000];
bool visit[1000];
vector<vector<pair<int, int>>> vt;
int func(int start, int end) {
	memset(visit, false, sizeof(visit));
	memset(dist, INF, sizeof(dist));
	priority_queue<pair<int, int>> qu;
	dist[start] = 0;
	qu.push({ dist[start], start });
	while (!qu.empty()) {
		int here = qu.top().second;
		qu.pop();
		if (visit[here]) continue;
		visit[here] = true;
		for (int i = 0; i < vt[here].size(); i++) {
			int there = vt[here][i].first;
			int cost = vt[here][i].second;
			if (dist[there] > dist[here] + cost) {
				dist[there] = dist[here] + cost;
				qu.push({ -dist[there], there });
			}
		}
	}
	return dist[end];
}
int main() {
	scanf("%d %d", &n, &m);
	vt.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		vt[a].push_back({ b, c });
		vt[b].push_back({ a, c });
	}
	scanf("%d %d", &f, &g);
	if (func(f, g) == INF || func(1, f) == INF || func(1, g) == INF || func(f, n) == INF || func(g, n) == INF) {
		puts("-1");
		return 0;
	}
	int res = 0, ftemp = 0, gtemp = 0;
	ftemp = func(1, f) + func(f, g) + func(g, n);
	gtemp = func(1, g) + func(g, f) + func(f, n);
	res = min(ftemp, gtemp);
	printf("%d\n", res);

	return 0;
}