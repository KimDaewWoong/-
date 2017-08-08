#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#define INF 0x3F3F3F3F
using namespace std;
int n, t, m, l;
int dist[110][10010];
vector<vector<pair<int, pair<int, int>>>> vt;
int main() {
	freopen("input.txt", "r", stdin);
	memset(dist, INF, sizeof(dist));
	scanf("%d %d %d %d", &n, &t, &m, &l);
	vt.resize(n + 1);
	for (int i = 0; i < l; i++) {
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		//번호, 이동시간, 택시비
		vt[a].push_back({ b,{ c, d } });
		vt[b].push_back({ a,{ c, d } });
	}

	dist[1][0] = 0;
	priority_queue<pair<int, pair<int, int>>> pq;
	pq.push({ -dist[1][0],{ 1, 0 } });
	while (!pq.empty()) {
		int here = pq.top().second.first;
		int cost = -pq.top().first;
		int time = pq.top().second.second;
		pq.pop();

		if (dist[here][time] > cost) continue;

		for (int i = 0; i < vt[here].size(); i++) {
			int there = vt[here][i].first;
			int thereTime = vt[here][i].second.first;
			int thereCost = vt[here][i].second.second;
			if (time + thereTime > t || cost + thereCost > m) continue;
			if (dist[there][time + thereTime] > dist[here][time] + thereCost) {
				dist[there][time + thereTime] = dist[here][time] + thereCost;
				pq.push({ -dist[there][time + thereTime],{ there, time + thereTime } });
			}
		}
	}
	int res = INF;
	for (int i = 0; i <= t; i++)
		res = min(res, dist[n][i]);

	if (res == INF) puts("-1");
	else printf("%d\n", res);

	return 0;
}