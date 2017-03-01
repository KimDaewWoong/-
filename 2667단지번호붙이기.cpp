#include<iostream>
#include<cstdio>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;
int map[30][30];
bool bv[30][30];
int dan[100];
//		╩С го аб ©Л
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1 ,0 ,0 };
int N, cnt, num;
queue <pair<int, int>> qu;
void func(int y, int x) {
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
				if (ny > N || nx > N) continue;
				if (map[ny][nx] == 1 && !bv[ny][nx]) {
					bv[ny][nx] = true;
					qu.push({ ny, nx });
				}
			}
			cnt++;
		}
	}
	num++;
}
int main() {
	freopen("input.txt", "r", stdin);
	string temp;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		cin >> temp;
		for (int j = 1; j <= N; j++) {
			map[i][j] = temp[j-1] - '0';
		}
	}
	int c = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (map[i][j] == 1 && !bv[i][j]){
				func(i, j);
				if (cnt != 0) {
					dan[c] = cnt;
					cnt = 0;
					c++;
				}
			}
		}
	}
	sort(dan, dan + c);
	printf("%d\n", num);
	for (int i = 0; i < c; i++)
		printf("%d\n", dan[i]);
	return 0;
}