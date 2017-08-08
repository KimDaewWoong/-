#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#define INF 0x3f3f3f3f
using namespace std;
int n, m, s, d, u, v, p;
int dist[550], arr[550][550];
bool visit[550];
vector<int> path;
void dijkstra() {
	memset(dist, INF, sizeof(dist));
	memset(visit, false, sizeof(visit));
	priority_queue <pair<int, int>> pq;
	dist[s] = 0;
	pq.push({ -dist[s], s });
	while (!pq.empty()) {
		int here = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();
		if (visit[here]) continue;
		visit[here] = true;
		dist[here] = cost;
		for (int i = 0; i < n; i++) {
			if (arr[here][i] == INF || dist[i] != INF) continue;
			int Ncost = arr[here][i] + cost;
			pq.push({ -Ncost, i });
		}
	}
}
void func() {
	queue<int> qu;
	qu.push(d);
	while (!qu.empty()) {
		int here = qu.front();
		qu.pop();
		for (int i = 0; i < n; i++) {
			if (dist[here] == dist[i] + arr[i][here] && arr[i][here] != INF) {
				arr[i][here] = INF;
				qu.push(i);
			}
		}
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	while (scanf("%d %d", &n, &m) != EOF && (n || m)) {
		memset(arr, INF, sizeof(arr));
		scanf("%d %d", &s, &d);
		for (int i = 0; i < m; i++) {
			scanf("%d %d %d", &u, &v, &p);
			arr[u][v] = p;
		}
		dijkstra(); func(); dijkstra();

		if (dist[d] == INF) puts("-1");
		else printf("%d\n", dist[d]);
	}
	return 0;
}