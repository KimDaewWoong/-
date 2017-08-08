#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<string>
#include<iostream>
#define INF 0x3F3F3F3F
using namespace std;
int n, m, dist[1010];
bool visit[1010];
string str;
vector<vector<pair<int, int>>> vt;
int func(int a, int b) {
	dist[1] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({ dist[1], 1 });
	while (!pq.empty()) {
		int here = pq.top().second;
		pq.pop();
		if (visit[here]) continue;
		visit[here] = true;
		for (int i = 0; i < vt[here].size(); i++) {
			int there = vt[here][i].first;
			int cost = vt[here][i].second;
			if ((here == a && there == b) || (here == b && there == a)) continue;
			if (dist[there] > dist[here] + cost && !visit[there]) {
				dist[there] = dist[here] + cost;
				pq.push({ -dist[there], there });
			}
		}
	}
	return dist[n];
}
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &n, &m);
	vt.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b, t;
		scanf("%d %d %d", &a, &b, &t);
		vt[a].push_back({ b, t });
		vt[b].push_back({ a, t });
	}
	memset(dist, INF, sizeof(dist));
	dist[1] = 0;
	priority_queue<pair<int, int>> pq;
	vector<int> path(n + 1, -1);
	pq.push({ dist[1], 1 });
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
				path[there] = here;
			}
		}
	}
	int minn = dist[n];
	int maxx = 0;

	for (int i = 1; i < path.size(); i++) {
		if (path[i] != -1) {
			memset(dist, INF, sizeof(dist));
			memset(visit, false, sizeof(visit));
			maxx = max(maxx, func(i, path[i]));
		}
	}
	if (maxx == INF)
		puts("-1");
	else
		printf("%d\n", maxx - minn);

	return 0;
}