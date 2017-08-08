#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
#define INF 0x3F3F3F3F
using namespace std;
int n, m, dist[125][125], map[125][125], cnt;
bool visit[125][125];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
bool isPossible(int y, int x) {
	if (y < 0 || x < 0 || y >= n || x >= m) return false;
	return true;
}
int main() {
	scanf("%d %d", &m, &n);
	memset(dist, 0x3F, sizeof(dist));
	memset(visit, false, sizeof(visit));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%1d", &map[i][j]);

	priority_queue <pair<int, int>> pq;

	dist[0][0] = map[0][0];
	pq.push({ dist[0][0], 0 });
	while (!pq.empty()) {
		int here = pq.top().second;
		pq.pop();
		int cy = here / 100;
		int cx = here % 100;
		if (visit[cy][cx]) continue;
		visit[cy][cx] = true;
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (isPossible(ny, nx)) {
				if (dist[ny][nx] > dist[cy][cx] + map[ny][nx] && !visit[ny][nx]) {
					dist[ny][nx] = dist[cy][cx] + map[ny][nx];
					pq.push({ -dist[ny][nx], (ny * 100) + nx });
				}
			}
		}
	}

	printf("%d\n", dist[n - 1][m - 1]);

	return 0;
}