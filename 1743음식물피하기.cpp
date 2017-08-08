#include<cstdio>
#include<algorithm>
using namespace std;
int arr[110][110];
bool visit[110][110];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int n, m, k, maxx, cnt;
bool isPossible(int y, int x) {
	if (y < 1 || x < 1 || y > n || x > m) return true;
	return false;
}
void dfs(int y, int x) {
	visit[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (isPossible(ny, nx)) continue;
		if (arr[ny][nx] && !visit[ny][nx]) {
			cnt++;
			dfs(ny, nx);
		}
	}
	maxx = max(maxx, cnt);
	return;
}
int main() {
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < k; i++) {
		int x, y;
		scanf("%d %d", &y, &x);
		arr[y][x] = 1;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (arr[i][j] && !visit[i][j]) {
				cnt = 1;
				dfs(i, j);
			}
		}
	}
	printf("%d", maxx);

	return 0;
}