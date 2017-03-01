#include<iostream>
#include<cstdio>

using namespace std;

int n[51][51];
//			 ╩С го аб ©Л
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };
int t, a, b, c, d, e, f, k;
bool tf(int, int);
void cabbage(int, int);
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &t);
	while (t--) {
		d = 0;
		cin >> b >> a >> k;
		while (k--) {
			cin >> f >> e;
			n[e][f] = 1;
		}
		for (int i = 0; i < a; i++) {
			for (int j = 0; j < b; j++) {
				if (n[i][j] == 1) {
					cabbage(i, j);
					d++;
				}
			}
		}
		printf("%d\n", d);
	}
	return 0;
}
bool tf(int x, int y) {

	if (x >= 0 && y >= 0 && x < a && y < b && n[x][y] == 1) return true;
	return false;
}
void cabbage(int x, int y) {
	n[x][y] = 0;
	for (int i = 0; i < 4; i++) {
		int nextx = x + dx[i];
		int nexty = y + dy[i];
		if (tf(nextx, nexty)) {
			cabbage(nextx, nexty);
		}
	}
}