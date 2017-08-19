#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
int dx[8] = { 2, 2, 1, -1, -2, -2, -1, 1 };
int dy[8] = { -1, 1, 2, 2, 1, -1, -2, -2 };
int map[330][330];
bool visit[330][330];
int n;

bool isPossible(int y, int x) {
	if (x < 0 || y < 0 || x >= n || y >= n) return false;
	return true;
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		memset(map, 0, sizeof(map));
		memset(visit, false, sizeof(visit));
		scanf("%d", &n);
		int a, b, cnt = 0;
		scanf("%d %d", &a, &b);
		map[a][b] = 1;
		queue<pair<int, int>> qu;
		qu.push({ a, b });
		visit[a][b] = 1;


		scanf("%d %d", &a, &b);
		map[a][b] = 2;

		bool flag = false;
		while (int s = qu.size()) {
			while (s--) {
				if (flag) break;
				int cx = qu.front().first;
				int cy = qu.front().second;
				qu.pop();

				if (map[cx][cy] == 2) {
					printf("%d\n", cnt);
					flag = true;
					break;
				}

				for (int i = 0; i < 8; i++) {
					int ny = cy + dy[i];
					int nx = cx + dx[i];
					if (isPossible(nx, ny) && !visit[nx][ny]) {
						visit[nx][ny] = 1;
						qu.push({ nx, ny });
					}
				}
			}
			if (flag) break;
			cnt++;
		}
	}
	return 0;
