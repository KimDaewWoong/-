#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#define INF 0x3F3F3F3F
using namespace std;
int t, n;
int road[110][110];
bool visit[110];
pair<int, int> arr[150];
vector<vector<int>> vt;
void dfs(int here) {
	visit[here] = true;
	for (int i = 0; i < vt[here].size(); i++) {
		int there = vt[here][i];
		if (!visit[there]) dfs(there);
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &t);
	while (t--) {
		memset(road, INF, sizeof(road));
		scanf("%d", &n);
		int x, y;
		scanf("%d %d", &arr[0].first, &arr[0].second);
		for (int i = 1; i <= n; i++) {
			scanf("%d %d", &arr[i].first, &arr[i].second);
		}
		scanf("%d %d", &arr[n + 1].first, &arr[n + 1].second);

		for (int i = 0; i <= n + 1; i++) {
			for (int j = i + 1; j <= n + 1; j++) {
				if (abs(arr[i].first - arr[j].first) + abs(arr[i].second - arr[j].second) <= 1000) {
					road[i][j] = abs(arr[i].first - arr[j].first) + abs(arr[i].second - arr[j].second);
				}
			}
		}

		for (int k = 1; k <= n; k++) {
			road[k][k] = 0;
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					road[i][j] = road[j][i] = min(road[i][j], road[i][k] + road[k][j]);
				}
			}
		}
		vt.resize(n + 2);
		for (int i = 0; i <= n + 1; i++) {
			for (int j = 0; j <= n + 1; j++) {
				if (i == j) continue;
				if (road[i][j] <= 1000) vt[i].push_back(j);
			}
		}

		memset(visit, false, sizeof(visit));
		dfs(0);

		vt.clear();

		printf("%s\n", visit[n + 1] ? "happy" : "sad");
	}
	return 0;
}