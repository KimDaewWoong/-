#include<cstdio>
#include<queue>
using namespace std;
int box[1010][1010];
//			╩С го аб ©Л
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1 , -1, 0, 0 };
int N, M, cnt;
int t = 1;
queue<pair<int, int>> qu;
void tomato() {
	while (int s = qu.size()) {
		while (s--) {
			int cx = qu.front().second;
			int cy = qu.front().first;
			qu.pop(); cnt--;
			for (int i = 0; i < 4; i++) {
				int nx = cx + dx[i];
				int ny = cy + dy[i];
				if (nx < 1 || nx > M || ny < 1 || ny > N) continue;
				if (box[ny][nx] == 0) {
					box[ny][nx] = box[cy][cx]+1;
					if (t < box[ny][nx]) t = box[ny][nx];
					qu.push({ ny, nx });
				}
			}
		}
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &M, &N);
	int fx, fy;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%d", &box[i][j]);
			if (box[i][j] == 1 || box[i][j] == 0) {
				cnt++;
				if (box[i][j] == 1) {
					qu.push({ i, j });
				}
			}
		}
	}
	tomato();

	if (cnt == 0) {
		printf("%d", t - 1);
	}
	else {
		puts("-1");
	}
	return 0;
}