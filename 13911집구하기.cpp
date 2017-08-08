#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#define INF 0x3F3F3F3F
using namespace std;
int V, E, M, x, S, y, M_dist[10100], S_dist[10100];
bool visit[10100];
vector<vector<pair<int, int>>> vt;
priority_queue<pair<int, int>> Mpq, Spq;
int main() {
	freopen("input.txt", "r", stdin);
	memset(M_dist, INF, sizeof(M_dist));
	memset(S_dist, INF, sizeof(S_dist));

	scanf("%d %d", &V, &E);
	vt.resize(V + 1);
	for (int i = 0; i < E; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		vt[u].push_back({ v, w });
		vt[v].push_back({ u, w });
	}
	scanf("%d %d", &M, &x);
	for (int i = 0; i < M; i++) {
		int node;
		scanf("%d", &node);
		M_dist[node] = 0;
		Mpq.push({ 0, node });
	}
	scanf("%d %d", &S, &y);
	for (int i = 0; i < S; i++) {
		int node;
		scanf("%d", &node);
		S_dist[node] = 0;
		Spq.push({ 0, node });
	}
	while (!Mpq.empty()) {
		int here = Mpq.top().second;
		Mpq.pop();
		if (visit[here]) continue;
		visit[here] = true;
		for (int i = 0; i < vt[here].size(); i++) {
			int there = vt[here][i].first;
			int cost = vt[here][i].second;
			if (M_dist[there] > M_dist[here] + cost) {
				M_dist[there] = M_dist[here] + cost;
				Mpq.push({ -M_dist[there], there });
			}
		}
	}

	memset(visit, false, sizeof(visit));
	while (!Spq.empty()) {
		int here = Spq.top().second;
		Spq.pop();
		if (visit[here]) continue;
		visit[here] = true;
		for (int i = 0; i < vt[here].size(); i++) {
			int there = vt[here][i].first;
			int cost = vt[here][i].second;
			if (S_dist[there] > S_dist[here] + cost) {
				S_dist[there] = S_dist[here] + cost;
				Spq.push({ -S_dist[there], there });
			}
		}
	}


	int res = INF;
	for (int i = 1; i <= V; i++) {
		if (M_dist[i] == INF || S_dist[i] == INF) continue;
		if (M_dist[i] != 0 && S_dist[i] != 0 && M_dist[i] <= x && S_dist[i] <= y) {
			res = min(res, M_dist[i] + S_dist[i]);
		}
	}
	if (res == INF) puts("-1");
	else printf("%d\n", res);
	return 0;
}