#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#define INF 0x3F3F3F3F
using namespace std;
priority_queue<pair<int, int>> pq;
vector<pair<int, int>> vt[1010];
int n, m, S, E, dist[1010];
int main() {
	memset(dist, INF, sizeof(dist));
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		vt[u].push_back({ v, w });
	}
	scanf("%d %d", &S, &E);
	dist[S] = 0;
	pq.push({ dist[S], S });
	while (!pq.empty()) {
		int cost = pq.top().first;
		int here = pq.top().second;
		pq.pop();
		if (dist[here] < cost) continue;
		for (int i = 0; i < vt[here].size(); i++) {
			int there = vt[here][i].first;
			int d = vt[here][i].second;
			if (dist[there] > dist[here] + d) {
				dist[there] = dist[here] + d;
				pq.push({ -dist[there], there });
			}
		}
	}
	printf("%d", dist[E]);

	return 0;
}