#include<cstdio>
#include<cstring>

int m, n;
int a[550][550];
int dp[550][550];
long long func(int x, int y) {
	if (x > n || y > m || x < 0 || y < 0) return 0;
	int& ret = dp[x][y];
	if (ret != -1) return ret;
	ret = 0;
	//©Л
	if (a[x][y] > a[x + 1][y] && x<n) ret += func(x + 1, y);
	//аб
	if (a[x][y] > a[x - 1][y] && x>0) ret += func(x - 1, y);
	//╩С
	if (a[x][y] > a[x][y -1] && y>0) ret += func(x, y - 1);
	//го
	if (a[x][y] > a[x][y + 1] && y<m) ret += func(x, y + 1);

	if (x == n - 1 && y == m - 1) ret = 1;
		
	return ret;
}
int main() {
	freopen("input.txt", "r", stdin);
	memset(dp, -1, sizeof(dp));
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &a[i][j]);
	printf("%lld", func(0, 0));
	return 0;
}