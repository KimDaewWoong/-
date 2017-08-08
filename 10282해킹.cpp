#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cstring>
#define INF 0x3F3F3F3F
using namespace std;
int t, n, m, start, dist[10010];
bool visit[10010];
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &t);
	while (t--) {
		memset(dist, INF, sizeof(dist));
		memset(visit, false, sizeof(visit));
		vector<vector<pair<int, int>>> vt;
		scanf("%d %d %d", &n, &m, &start);
		vt.resize(n + 1);
		for (int i = 0; i < m; i++) {
			int u, v, w;
			scanf("%d %d %d", &v, &u, &w);
			vt[u].push_back({ v,w });
		}
		dist[start] = 0;
		priority_queue<pair<int, int>> pq;
		pq.push({ dist[start], start });
		while (!pq.empty()) {
			int here = pq.top().second;
			pq.pop();
			if (visit[here]) continue;
			visit[here] = true;
			for (int i = 0; i < vt[here].size(); i++) {
				int there = vt[here][i].first;
				int cost = vt[here][i].second;
				if (dist[there] > dist[here] + cost && !visit[there]) {
					dist[there] = dist[here] + cost;
					pq.push({ -dist[there], there });
				}
			}
		}
		int cnt = 0, maxx = 0;
		for (int i = 1; i <= n; i++) {
			if (dist[i] == INF) continue;
			cnt++;
			maxx = max(maxx, dist[i]);
		}
		printf("%d %d\n", cnt, maxx);
	}
	return 0;
}