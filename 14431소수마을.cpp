#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstring>
#include<cmath>
#define INF 0x3F3F3F3F
using namespace std;
int x, y, n, dist[4010];
bool b[10010], visit[4010];
pair<int, int> arr[4010];
vector<vector<pair<int, int>>> vt;
priority_queue<pair<int, int>> pq;
int main() {
	memset(dist, INF, sizeof(dist));
	memset(visit, false, sizeof(visit));

	b[0] = b[1] = true;
	for (int i = 2; i <= 10000; i++) {
		if (b[i]) continue;
		for (int j = i*i; j <= 10000; j += i) {
			b[j] = true;
		}
	}

	scanf("%d %d %d %d %d", &arr[0].first, &arr[0].second, &x, &y, &n);
	vt.resize(n + 2);

	for (int i = 1; i <= n; i++)
		scanf("%d %d", &arr[i].first, &arr[i].second);

	arr[n + 1].first = x; arr[n + 1].second = y;
	for (int i = 0; i <= n + 1; i++) {
		for (int j = i + 1; j <= n + 1; j++) {
			int temp = sqrt((arr[i].first - arr[j].first)*(arr[i].first - arr[j].first) +
				(arr[i].second - arr[j].second) * (arr[i].second - arr[j].second));
			if (!b[temp]) {
				vt[i].push_back({ j, temp });
				vt[j].push_back({ i, temp });
			}
		}
	}

	dist[0] = 0;
	pq.push({ dist[0], 0 });
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
	if (dist[n + 1] == INF) puts("-1");
	else printf("%d\n", dist[n + 1]);
	return 0;
}