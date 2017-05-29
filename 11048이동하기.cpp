#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int dp[1010][1010], arr[1010][1010];
int n, m;

int func(int y, int x) {
	if (y >= n || x >= m) return 0;
	int& ret = dp[y][x];
	if (ret != -1) return ret;
	ret = arr[y][x];
	ret += max(max(func(y + 1, x), func(y, x + 1)), func(y + 1, x + 1));
	return ret;
}
int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	printf("%d", func(0, 0));
	return 0;
}