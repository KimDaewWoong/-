#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
#define INF 0x3F3F3F3F
using namespace std;
int n, dist[125][125], map[125][125], cnt;
bool visit[125 * 125];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
bool isPossible(int y, int x) {
	if (y < 0 || x < 0 || y >= n || x >= n) return false;
	return true;
}
int main() {
	while (scanf("%d", &n) && n != 0) {
		memset(map, -1, sizeof(map));
		memset(dist, 0x3F, sizeof(dist));
		memset(visit, false, sizeof(visit));

		for (int i = 0; i < n; i++)
			for (int j = 0; j<n; j++)
				scanf("%d", &map[i][j]);

		priority_queue <pair<int, int>> pq;

		dist[0][0] = map[0][0];
		pq.push({ dist[0][0], 0 });
		while (!pq.empty()) {
			int here = pq.top().second;
			pq.pop();
			if (visit[here]) continue;
			visit[here] = true;
			int cx = here / n;
			int cy = here % n;
			for (int i = 0; i <4; i++) {
				int nx = cx + dx[i];
				int ny = cy + dy[i];
				if (isPossible(ny, nx)) {
					if (dist[ny][nx] > dist[cy][cx] + map[ny][nx]) {
						dist[ny][nx] = dist[cy][cx] + map[ny][nx];
						pq.push({ -dist[ny][nx], (nx*n) + ny });
					}
				}
			}
		}
		int a = n - 1;
		printf("Problem %d: %d\n", ++cnt, dist[a][a]);
	}
	return 0;
}