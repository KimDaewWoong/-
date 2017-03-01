#include<cstdio>

int a[101];//가지 수
int b[1001];//개수
int dp[101][10001];
int t, k;

int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &t, &k);
	dp[0][0] = 1;
	for (int i = 1; i <= k; i++) {
		dp[i][0] = 1;
		scanf("%d %d", &a[i], &b[i]);
	}
	for (int i = 1; i <= k; i++)
		for (int j = 1; j <= t; j++)
			for (int h = 0; h <= b[i]; h++) {
				if (a[i] * h > j) break;
				dp[i][j] += dp[i - 1][j - (a[i] * h)];
			}
	printf("%d\n", dp[k][t]);

	return 0;
}