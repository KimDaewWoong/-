#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#define INF 0x3f3f3f3f
using namespace std;
int n, k;
int dist[100100], path_log[100100];
bool visit[100100];
vector<int> path;
int main() {
	memset(dist, INF, sizeof(dist));
	scanf("%d %d", &n, &k);

	dist[n] = 0;
	priority_queue<pair<int, pair<int, int>>> pq;
	pq.push({ -dist[n],{ n, INF } });
	while (!pq.empty()) {
		int here = pq.top().second.first;
		int prev = pq.top().second.second;
		int cost = -pq.top().first;
		pq.pop();
		if (visit[here]) continue;
		visit[here] = true;
		path_log[here] = prev;
		dist[here] = cost;
		if (here == k) break;
		int d[3] = { here + 1, here - 1, here * 2 };
		for (int i = 0; i < 3; i++) {
			int there = d[i];
			if (0 <= there && there <= 100000 && !visit[there]) {
				pq.push({ -(cost + 1),{ there, here } });
			}
		}
	}

	int idx = k;
	printf("%d\n", dist[k]);
	while (idx != INF) {
		path.push_back(idx);
		idx = path_log[idx];
	}

	for (int i = path.size() - 1; i >= 0; i--)
		printf("%d ", path[i]);

	return 0;
}