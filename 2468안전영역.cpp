#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
int area[120][120];
bool check[120][120];
int N, cnt, maxv, ans;
// ╩С го аб ©Л
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
queue<pair<int, int>> qu;
void safetyarea(int y, int x, int z) {
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
				if (ny > N || nx > N) continue;
				if (area[ny][nx] > z && !check[ny][nx]) {
					check[ny][nx] = true;
					qu.push({ ny,nx });
				}
			}
		}
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &area[i][j]);
			if (maxv <= area[i][j]) maxv = area[i][j];
		}
	}
	for (int k = 0; k <= maxv; k++) {
		cnt = 0;
		memset(check, false, sizeof(check));
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				if (check[i][j] == false && area[i][j]>k) {
					check[i][j] = true;
					safetyarea(i, j, k);
					cnt++;
				}
		if (cnt > ans) ans = cnt;
	}
	printf("%d", ans);
	return 0;
}