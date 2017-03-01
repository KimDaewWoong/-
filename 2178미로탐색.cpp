#include<iostream>
#include<cstdio>
#include<queue>
#include<string>
#include<cstring>
using namespace std;
int map[110][110];
bool bv[110][110];
//			╩С го аб ©Л
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0 ,0 };
int N, M, cnt;
queue<pair<int, int>> qu;
bool notgood(int y, int x) {
	return (y >= N || x >= M || y < 0 || x < 0);
}
void miro(int y, int x) {
	bv[y][x] = true;
	qu.push({ y, x });
	while (int s = qu.size()) {
		while (s--) {
			int cx = qu.front().second;
			int cy = qu.front().first;
			qu.pop();
			for (int i = 0; i < 4; i++) {
				int nx = cx + dx[i];
				int ny = cy + dy[i];
				if (notgood(nx, ny))
					continue;
				if (map[ny][nx] == 1 && !bv[ny][nx]) {
					bv[ny][nx] = true;
					qu.push({ny, nx});
				}
			}
		}
		cnt++;
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	memset(bv, false, sizeof(bv));
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		string a;
		cin >> a;
		for (int j = 0; j < M;j++) {
			map[j][i] = a[j]-'0';
		}
	}
	miro(0, 0);
	printf("%d", cnt);
	return 0;
}