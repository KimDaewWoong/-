#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
#define INF 0x3F3F3F3F
using namespace std;
int n, m, x, dist[1010], rev_dist[1010];
bool visit[1010];
vector<vector<pair<int, int>>> vt;
vector<vector<pair<int, int>>> rev;
int main() {
	scanf("%d %d %d", &n, &m, &x);
	vt.resize(n + 1);
	rev.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		vt[u].push_back({ v,w });
		rev[v].push_back({ u,w });
	}
	memset(dist, 0x3F, sizeof(dist));
	memset(visit, false, sizeof(visit));
	priority_queue <pair<int, int>> pq;
	dist[x] = 0;
	pq.push({ dist[x], x });
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
	//rev
	memset(rev_dist, 0x3F, sizeof(rev_dist));
	memset(visit, false, sizeof(visit));
	priority_queue <pair<int, int>> pq2;
	rev_dist[x] = 0;
	pq2.push({ rev_dist[x], x });
	while (!pq2.empty()) {
		int here = pq2.top().second;
		pq2.pop();
		if (visit[here]) continue;
		visit[here] = true;
		for (int i = 0; i < rev[here].size(); i++) {
			int there = rev[here][i].first;
			int cost = rev[here][i].second;
			if (rev_dist[there] > rev_dist[here] + cost) {
				rev_dist[there] = rev_dist[here] + cost;
				pq2.push({ -rev_dist[there], there });
			}
		}
	}

	int maxx = 0;
	for (int i = 1; i <= n; i++) {
		maxx = max(maxx, dist[i] + rev_dist[i]);
	}
	printf("%d", maxx);

	return 0;
}