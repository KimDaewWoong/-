#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
int map[110][110];
int temp[110][110];
bool check[110][100];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };
int n, m, cnt;
bool ch = true;
queue <pair<int, int>> qu;
void func(int y, int x) {
	qu.push({ y, x });
	check[y][x] = true;
	while (int s = qu.size()) {
		while (s--) {
			int cx = qu.front().second;
			int cy = qu.front().first;
			qu.pop();
			for (int i = 0; i < 4; i++) {
				int nx = cx + dx[i];
				int ny = cy + dy[i];
				if (ny<0||nx<0||ny > n || nx > m) continue;
				if (map[ny][nx] == 1 && !check[ny][nx]) temp[ny][nx]++;
				if (map[ny][nx] == 0 && !check[ny][nx]) {
					check[ny][nx] = true;
					qu.push({ ny, nx });
				}
			}
		}
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	while (ch) {
		memset(check, 0, sizeof(check));
		memset(temp, 0, sizeof(temp));
		func(0, 0); func(0, m - 1); func(n - 1, 0); func(n - 1, m - 1);
		cnt++;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (temp[i][j] >= 2) map[i][j] = 0;
			}
		}
		ch = false;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] == 1) {
					ch = true;
					break;
				}
			}
			if (ch) break;
		}
	}
	printf("%d", cnt);
	return 0;
}