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
string arr[1010];
vector<vector<pair<int, int>>> vt;
int main() {
	freopen("input.txt", "r", stdin);
	memset(dist, INF, sizeof(dist));
	scanf("%d", &n);
	vt.resize(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	int len = arr[1].size();
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			int sum = 0;
			for (int k = 0; k < len; k++) {
				sum += ((arr[i][k] - '0') - (arr[j][k] - '0')) * ((arr[i][k] - '0') - (arr[j][k] - '0'));
			}
			vt[i].push_back({ j, sum });
			vt[j].push_back({ i, sum });
		}
	}

	int source, sink;
	scanf("%d %d", &source, &sink);
	dist[source] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({ dist[source], source });
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
	printf("%d", dist[sink]);

	return 0;
}