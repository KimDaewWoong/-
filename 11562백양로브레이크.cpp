#include<cstdio>
#include<cstring>
#include<algorithm>
#define INF 0x3F3F3F3F
using namespace std;
int road[300][300];

int main() {
	memset(road, INF, sizeof(road));
	int n, m, k;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int u, v, b;
		scanf("%d %d %d", &u, &v, &b);
		//비용으로생각
		//0은 이동하는데 드는 비용이 0
		//1은 이동하는데 드는 비용이 1
		if (b) road[v - 1][u - 1] = 0;
		else road[v - 1][u - 1] = 1;
		road[u - 1][v - 1] = 0;
	}
	for (int i = 0; i < n; i++) road[i][i] = 0;

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				road[i][j] = min(road[i][j], road[i][k] + road[k][j]);
			}
		}
	}
	scanf("%d", &k);
	while (k--) {
		int s, e;
		scanf("%d %d", &s, &e);
		printf("%d\n", road[s - 1][e - 1]);
	}

	return 0;
}