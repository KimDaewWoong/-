#include<cstdio>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
int map[110][110];
vector<int> res;
bool visited[110][110];
int dx[4] = { 0 ,0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int n, m, k, cnt, abc;
bool isPossible(int y, int x) {
	if (y < 0 || x < 0 || y >= n || x >= m) return false;
	return true;
}
void bfs(int y, int x) {
	queue<pair<int, int>> qu;
	qu.push({ y,x });
	visited[y][x] = 1;
	abc = 0;
	while (!qu.empty()) {
		int cy = qu.front().first;
		int cx = qu.front().second;
		qu.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (isPossible(ny, nx) && !visited[ny][nx] && !map[ny][nx]) {
				qu.push({ ny, nx });
				visited[ny][nx] = true;
			}
		}
		abc++;
	}
}
int main() {
	scanf("%d %d %d", &n, &m, &k);

	for (int i = 0; i < k; i++) {
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		for (int i = min(b, d); i < max(b, d); i++) {
			for (int j = min(a, c); j < max(a, c); j++) {
				map[i][j] = 1;
			}
		}
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j] && !map[i][j]) {
				bfs(i, j);
				cnt++;
				res.push_back(abc);
			}
		}
	}

	sort(res.begin(), res.end());
	printf("%d\n", cnt);
	for (int i = 0; i < res.size(); i++) {
		printf("%d ", res[i]);
	}
	return 0;
}