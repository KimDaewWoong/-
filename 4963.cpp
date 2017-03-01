#include<iostream>
#include<cstdio>

using namespace std;

int n[51][51];
//╩С го аб ©Л ╩Саб ╩С©Л гоаб го©Л
int dx[8] = { 0, 0, -1, 1, 1, 1, -1, -1 };
int dy[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

int a, b, c, d;
bool tf(int, int);
void rand(int, int);
int main() {
	freopen("input.txt", "r", stdin);
	while (1) {
		d = 0;
		scanf("%d %d", &b, &a);
		if (a != 0 || b != 0) {
			for (int i = 0; i < a; i++) {
				for (int j = 0; j < b; j++) {
					scanf("%d", &n[i][j]);
				}
			}
			for (int i = 0; i < a; i++) {
				for (int j = 0; j < b; j++) {

					if (n[i][j] == 1) {
						rand(i, j);
						d++;
					}
				}
			}
		}
		else break;
		printf("%d\n", d);
	}
	return 0;
}
bool tf(int x, int y) {

	if (x>=0 && y>=0 && x < a && y < b && n[x][y]==1) return true;
	return false;
}
void rand(int x, int y){
	n[x][y] = 0;
	for (int i = 0; i < 8; i++) {
		int nextx = x + dx[i];
		int nexty = y + dy[i];
		if (tf(nextx, nexty)) {
			rand(nextx, nexty);
		}
	}
}