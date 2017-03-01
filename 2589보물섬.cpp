#include<iostream>
#include<cstdio>
#include<queue>
#include<string>
#include<cstring>
using namespace std;
int map[100][100];
bool check[100][100];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0 ,0 };
int n, m, cnt, maxv, q;
queue<pair<int, int>> qu;
void func(int y, int x) {
	qu.push({y, x });
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
				if (map[ny][nx] == 1 && !check[ny][nx]) {
					check[ny][nx] = true;
					qu.push({ ny, nx });
				}
			}
		}
		cnt++;
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &n, &m);
	string a;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		for (int j = 1; j <= m; j++) {
			if (a[j-1] == 'L') map[i][j] = 1;
			else map[i][j] = 0;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map[i][j]) {
				memset(check, false, sizeof(check));
				cnt = -1;
				func(i, j);
			}
			if (cnt > maxv) maxv = cnt;
		}
	}
	printf("%d", maxv);
	return 0;
}