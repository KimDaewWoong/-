#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
int map[330][330];
int temp[330][330];
bool check[330][330];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };
int n, m, cnt, year, ch, a;
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
				if (ny > n || nx > m) continue;
				if (map[ny][nx] != 0 && !check[ny][nx]) {
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
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &map[i][j]);
	while (1) {
		cnt = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (check[i][j] == false && map[i][j] != 0) { 
					func(j, i);
					cnt++;
				}
			}
		}
		if (cnt = 0) year = 0;
		memset(check, false, sizeof(check));
		if (cnt > 1) break;
		
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (map[i][j] != 0) {
					for (int k = 0; k < 4; k++) {
						int nx = j + dx[k];
						int ny = i + dy[k];
					if (map[ny][nx] == 0)	temp[i][j]++;
					}
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (temp[i][j] != 0) {
					map[i][j] -= temp[i][j];
					if (map[i][j] < 0) map[i][j] = 0;
				}
			}
		}
		memset(temp, 0, sizeof(temp));
	}
	
	printf("%d", year);
	return 0;
}