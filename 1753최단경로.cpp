#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
#include<cstring>
#define INF 0x3F3F3F3F
using namespace std;
int n, m, k, dist[20020];
bool visit[20020];
vector<pair<int, int>> vt[20020];
priority_queue<pair<int, int>> pq;
int main() {
	memset(dist, 0x3F, sizeof(dist));
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		vt[u].push_back({ v, w });
	}
	dist[k] = 0;
	pq.push({ 0, k });
	while (!pq.empty()) {
		int here = pq.top().second;
		pq.pop();
		if (visit[here]) continue;
		visit[here] = true;
		for (int i = 0; i < vt[here].size(); i++) {
			int there = vt[here][i].first;
			int cost = vt[here][i].second;
			if (dist[there] > dist[here] + cost) {
				dist[there] = dist[here] + cost;
				pq.push({ -dist[there], there });
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (dist[i] == INF) puts("INF");
		else printf("%d\n", dist[i]);
	}
	return 0;
}