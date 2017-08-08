#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
#define INF 0x3f3f3f3f
using namespace std;
int n, m, dist[1001];
bool visit[1001];
vector<pair<int, int>> res;
vector<vector<pair<int, int>>> vt;
int main() {
	scanf("%d %d", &n, &m);
	vt.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		vt[a].push_back({ b,c });
		vt[b].push_back({ a,c });
	}
	memset(dist, INF, sizeof(dist));
	priority_queue<pair<int, pair<int, int>>> pq;
	dist[1] = 0;
	pq.push({ 0,{ 1,0 } });
	while (pq.size()) {
		int here = pq.top().second.first;
		int cost = -pq.top().first;
		int d = pq.top().second.second;
		pq.pop();
		if (visit[here]) continue;
		visit[here] = true;
		if (d != 0)
			res.push_back({ here, d });
		for (int i = 0; i < vt[here].size(); i++) {
			int there = vt[here][i].first;
			int thereCost = vt[here][i].second;
			if (dist[there] != INF) continue;
			pq.push({ -(cost + thereCost),{ there, here } });
		}
	}
	printf("%d\n", res.size());
	for (int i = 0; i < res.size(); i++)
		printf("%d %d\n", res[i].first, res[i].second);

	return 0;
}