#include<cstdio>
#include<algorithm>
#include<cstring>
#define INF 0x3F3F3F3F
using namespace std;
int t, n, m;
int map[550][550], r[550], sum[550];
int main() {
	scanf("%d", &t);
	while (t--) {
		pair<pair<int, int>, int> pa[550];
		memset(map, 0x3F, sizeof(map));
		memset(r, 0, sizeof(r));
		memset(sum, 0, sizeof(sum));
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; i++) {
			int val;
			scanf("%d", &val);
			pa[i].first.second = -val;
			pa[i].second = i;
		}
		for (int i = 1; i <= m; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			map[a][b] = map[b][a] = 1;
		}

		for (int i = 1; i <= n; i++) map[i][i] = 0;

		for (int k = 1; k <= n; k++) {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
				}
			}
		}

		for (int i = 1; i <= n; i++) {
			int maxx = 0;
			for (int j = 1; j <= n; j++) {
				sum[i] += map[i][j];
				maxx = max(maxx, map[i][j]);
			}
			r[i] = maxx;
		}

		for (int i = 1; i <= n; i++)
			pa[i].first.first = (n - 1) * r[i] + sum[i];

		sort(pa, pa + n + 1);

		printf("%d\n", pa[1].second);
	}
	return 0;
}