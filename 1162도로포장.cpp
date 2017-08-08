#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#define INF 0x3F3F3F3F
using namespace std;
int n, m, k, dist[10010][25];
bool visit[10010];
vector<vector<pair<int, int>>> vt;
void func() {
	dist[1][k] = 0;
	priority_queue<pair<pair<int, int>, int>> pq;
	pq.push({ { 0, 1 }, k });
	while (!pq.empty()) {
		int here = pq.top().first.second;
		int cnt = pq.top().second;
		int hcost = -pq.top().first.first;
		pq.pop();

		for (int i = 0; i < vt[here].size(); i++) {
			int there = vt[here][i].first;
			int cost = vt[here][i].second;
			if (cnt > 0) {
				if (dist[there][cnt - 1] > hcost) {
					dist[there][cnt - 1] = hcost;
					pq.push({ { -dist[there][cnt - 1], there }, cnt - 1 });
				}
			}

			if (dist[there][cnt] > hcost + cost) {
				dist[there][cnt] = hcost + cost;
				pq.push({ { -dist[there][cnt], there }, cnt });
			}
		}
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	memset(dist, INF, sizeof(dist));
	scanf("%d %d %d", &n, &m, &k);
	vt.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b, t;
		scanf("%d %d %d", &a, &b, &t);
		vt[a].push_back({ b, t });
		vt[b].push_back({ a, t });
	}
	func();
	int minn = INF;
	for (int i = 0; i <= k; i++) {
		minn = min(minn, dist[n][i]);
	}

	printf("%d\n", minn);
	return 0;
}