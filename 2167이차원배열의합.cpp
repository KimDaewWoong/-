#include<cstdio>
#include<cstring>
using namespace std;
int n, m, val, k, a, b, c, d;
int map[330][330];
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &val);
			//받을 때부터 dp로, 좌+상-대각(중복)
			map[i][j] = val + map[i - 1][j] + map[i][j - 1] - map[i - 1][j - 1];
		}
	}
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		scanf("%d %d %d %d", &a, &b, &c, &d);
		//출력은 좌dp값+상dp값을 빼고 중복 뺀 대각을 더한다.
		printf("%d\n", map[c][d] - map[a - 1][d] - map[c][b - 1] + map[a - 1][b - 1]);
	}
	return 0;
}
