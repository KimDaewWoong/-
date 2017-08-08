#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#define INF 0x3f3f3f3f
using namespace std;
int T, n, m, t, s, g, h;
int d1[2200], d2[2200];
bool visit[2200], target[2200];
vector<vector<pair<int, int>>> vt;
void dijkstra(int source, int* dist) {
	memset(visit, false, sizeof(visit));
	priority_queue<pair<int, int>> pq;
	dist[source] = 0;
	pq.push({ -dist[source], source });
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
}
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &T);
	while (T--) {
		memset(d1, INF, sizeof(d1));
		memset(d2, INF, sizeof(d2));
		memset(target, false, sizeof(target));
		scanf("%d %d %d %d %d %d", &n, &m, &t, &s, &g, &h);
		vt.resize(n + 1);
		for (int i = 0; i < m; i++) {
			int a, b, d;
			scanf("%d %d %d", &a, &b, &d);
			vt[a].push_back({ b, d });
			vt[b].push_back({ a, d });
		}
		for (int i = 0; i < t; i++) {
			int x;
			scanf("%d", &x);
			target[x] = true;
		}
		//시작점에서 최단거리
		dijkstra(s, d1);
		int s2 = 0;
		if (d1[h] > d1[g]) s2 = h;
		else s2 = g;
		//브릿지에서 최단거리
		dijkstra(s2, d2);

		for (int i = 1; i <= n; i++) {
			if (!target[i] || d1[i] == INF || d2[i] == INF) continue;
			//시작점 최단거리 = 시작점에서 브릿지 최단거리 + 브릿지에서 목표점 최단거리
			if (d1[i] == d1[s2] + d2[i]) printf("%d ", i);
		}
		puts("");
		vt.clear();
	}
	return 0;
}