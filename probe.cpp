#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };
int arr[10][10];
bool visited[10][10];
int t, n, m, maxx, a, b;
bool isPossible(int y, int x) {
	if (y >= n || x >= n || y < 0 || x < 0) return false;
	return true;
}
void dfs(int y, int x, int cnt) {
	bool flag = false;
	for (int i = 0; i < 4; i++) {
		int nx = dx[i] + x;
		int ny = dy[i] + y;
		if (isPossible(ny, nx) && !arr[ny][nx] && !visited[ny][nx]) {
			flag = true;
			visited[y][x] = true;
			dfs(ny, nx, cnt + 1);
			visited[y][x] = false;
		}
	}
	if (!flag) {
		maxx = max(maxx, cnt);
		return;
	}
}
int main() {
	scanf("%d", &t);
	while (t--) {
		memset(arr, 0, sizeof(arr));
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &arr[i][j]);
			}
		}
		for (int k = 0; k < m; k++) {
			memset(visited, false, sizeof(visited));
			scanf("%d %d", &a, &b);
			maxx = 1;
			dfs(a, b, 1);
			printf("%d\n", maxx);
		}

	}


	return 0;
}