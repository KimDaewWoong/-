#include<cstdio>
#include<cstring>
using namespace std;
int map[25][25];
int dp[25][25][25][25][25];
			//»ó ÇÏ ÁÂ ¿ì »óÁÂ »ó¿ì ÇÏÁÂ ÇÏ¿ì
int dx[8] = { 0, 0, -1, 1, -1, 1, -1, 1 };
int dy[8] = { 1, -1, 0, 0, 1, 1, -1, -1 };
int n, L, sol;

bool tf(int x, int y) {
	return (x >= 0 && x < n && y >= 0 && y < n);
}

int func(int t, int lx, int ly, int rx, int ry) {
	//±âÀú»ç·Ê
	if (map[lx][ly] != map[rx][ry]) return 0;
	else if (t == L) return 1;
	
	int &ret = dp[t][lx][ly][rx][ry];
	if (ret != -1) return ret;

	ret = 0;
	for (int i = 0; i < 8; i++) {
		int nlx = lx + dx[i];
		int nly = ly + dy[i];
		if (tf(nlx, nly)) {
			for (int j = 0; j < 8; j++) {
				int nrx = rx + dx[j];
				int nry = ry + dy[j];
				if (tf(nrx, nry)) {
					ret += func(t + 2, nlx, nly, nrx, nry);
				}
			}
		}
	}
	return ret;
}
int main() {
	freopen("input.txt", "r", stdin);
	memset(dp, -1, sizeof(dp));
	scanf("%d %d", &n, &L);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	if (L % 2) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				sol += func(1, i, j, i, j);
			}
		}
	}else {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < 8; k++) {
					int ni = i + dx[k];
					int nj = j + dy[k];
					if (tf(ni, nj)) {
						sol += func(2, i, j, ni, nj);
					}
				}
			}
		}
	}
	printf("%d", sol);
	return 0;
}
