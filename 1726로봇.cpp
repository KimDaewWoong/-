#include<cstdio>
#include<queue>
using namespace std;
int n, m, cnt, map[110][110];
int sx, sy, sd, tx, ty, td;
		//회전x 동 서 남 북
int dx[5] = { 0, 1, -1, 0, 0 };
int dy[5] = { 0, 0, 0, 1, -1 };
bool b[110][110][5];
queue<pair<int, pair<int, int>>> qu;

int func(int y, int x, int d) {
	b[y][x][d] = true;
	qu.push({ y , { x, d } });
	while (int s = qu.size()) {
		while (s--) {
			int cx = qu.front().second.first;
			int cy = qu.front().first;
			int cd = qu.front().second.second;
			qu.pop();
			//기저
			if (cx == tx&&cy == ty&&cd == td) return cnt;
			//전진
			for (int i = 1; i <= 3; i++) {
				int nx = cx + dx[cd] * i;
				int ny = cy + dy[cd] * i;
				if (nx<1 || nx>m || ny<1 || ny>n || map[ny][nx] == 1) break;
				if (!b[ny][nx][cd]) {
					b[ny][nx][cd] = true;
					qu.push({ ny, {nx, cd} });
				}
			}
			//회전
			for (int i = 1; i <= 4; i++) {
				if (cd == i) continue;
				else if (cd == 1 && i == 2) continue;
				else if (cd == 2 && i == 1) continue;
				else if (cd == 3 && i == 4) continue;
				else if (cd == 4 && i == 3) continue;

				if (!b[cy][cx][i]) {
					b[cy][cx][i] = true;
					qu.push({ cy, {cx, i} });
				}
			}
		}
		cnt++;
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= m; j++) 
			scanf("%d", &map[i][j]);
	
	scanf("%d %d %d %d %d %d", &sy, &sx, &sd, &ty, &tx, &td);
	printf("%d", func(sy, sx, sd));

	return 0;
}