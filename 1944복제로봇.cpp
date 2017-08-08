#include<cstdio>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
int arr[55][55], p[2500], n, m, xx, yy;
bool visit[55][55];
pair<int, int> xy[2500];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int find(int u) {
	if (p[u] == u) return u;
	return p[u] = find(p[u]);
}
bool merge(int u, int v) {
	u = find(u); v = find(v);
	if (u == v) return false;
	p[u] = v;
	return true;
}
bool isPossible(int y, int x) {
	if (y >= n || x >= n || y < 0 || x < 0) return false;
	return true;
}
int bfs(int y, int x, int k) {
	queue<pair<int, int>> qu;
	int cnt = 0;
	bool flag = false;
	visit[y][x] = 1;
	qu.push({ y, x });
	if (arr[y][x] == k) return 0;
	while (int s = qu.size()) {
		while (s--) {
			int cx = qu.front().second;
			int cy = qu.front().first;
			qu.pop();
			for (int i = 0; i < 4; i++) {
				int nx = cx + dx[i];
				int ny = cy + dy[i];
				if (isPossible(ny, nx) && arr[ny][nx] != 1 && !visit[ny][nx]) {
					if (arr[ny][nx] == k) {
						flag = true;
						break;
					}
					qu.push({ ny, nx });
					visit[ny][nx] = 1;
				}
			}
			if (flag) return cnt + 1;
		}
		cnt++;
	}
	return -1;
}
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &n, &m);
	for (int i = 0; i <= n*n; i++) p[i] = i;
	int k = 3;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char c;
			scanf(" %1c", &c);
			if (c == '1') arr[i][j] = 1;
			if (c == 'S') {
				arr[i][j] = 2;
				xy[2] = { i, j };
			}
			if (c == 'K') {
				arr[i][j] = k;
				xy[k++] = { i, j };
			}
		}
	}

	vector < pair<int, pair<int, int>>> vt;
	for (int i = 2; i <= m + 2; i++) {
		xx = xy[i].second;
		yy = xy[i].first;
		for (int j = i + 1; j <= m + 2; j++) {
			memset(visit, 0, sizeof(visit));
			int w = bfs(yy, xx, j);
			if (w == -1) {
				puts("-1");
				return 0;
			}
			if (!w) continue;
			vt.push_back({ w,{ i, j } });
		}
	}
	sort(vt.begin(), vt.end());

	int res = 0;
	for (int i = 0; i < vt.size(); i++) {
		if (merge(vt[i].second.first, vt[i].second.second))
			res += vt[i].first;
	}
	printf("%d", res);

	return 0;
}