#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
int n, m, arr[310][310], temp[310][310], res;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };
bool visited[310][310];
int isPossible(int y, int x) {
	if (y >= 0 && x >= 0 && y < n && x < m) return true;
	return false;
}
void func(int y, int x) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (isPossible(ny, nx) && !arr[ny][nx]) {
			temp[y][x]++;
		}
	}
}
void dfs(int y, int x) {
	visited[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (isPossible(ny, nx) && !visited[ny][nx] && arr[ny][nx]) {
			dfs(ny, nx);
		}
	}
}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	while (1) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j])
					func(i, j);
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				arr[i][j] -= temp[i][j];
				if (arr[i][j] < 0) arr[i][j] = 0;
			}
		}
		int cnt = 0;
		memset(visited, false, sizeof(visited));
		memset(temp, false, sizeof(temp));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] && !visited[i][j]) {
					dfs(i, j);
					cnt++;
				}
			}
		}
		res++;
		if (cnt >= 2) {
			printf("%d\n", res);
			break;
		}
		else if (!cnt) {
			puts("0");
			break;
		}
	}
	return 0;
}