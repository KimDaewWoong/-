#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<string>
#include<iostream>
#define INF 0x3F3F3F3F
using namespace std;
int n, dist[1010];
bool visit[1010];
string str;
vector<vector<pair<int, int>>> vt;
int main() {
	freopen("input.txt", "r", stdin);
	memset(dist, INF, sizeof(dist));

	scanf("%d", &n);
	vt.resize(n + 1);
	cin >> str;

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if ((str[i] == 'B' && str[j] == 'O') || (str[i] == 'O' && str[j] == 'J') || (str[i] == 'J' && str[j] == 'B')) {
				int d = (j - i) * (j - i);
				vt[i].push_back({ j, d });
			}
		}
	}

	dist[0] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({ dist[0], 0 });
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
			}
		}
	}
	if (dist[n - 1] == INF) puts("-1");
	else printf("%d", dist[n - 1]);

	return 0;
}