#include<cstdio>
#define MOD 1000000007
int n, l, r;
long long dp[110][110][110];
//dp[n][[l][r];

int main() {
	long long temp;
	scanf("%d %d %d", &n, &l, &r);

	dp[1][1][1] = 1;
	dp[2][2][1] = dp[2][1][2] = 1;

	for (int i = 3; i <= n; i++) {
		dp[i][i][1] = dp[i][1][i] = 1;
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				temp = dp[i - 1][j][k];
				temp = (temp * (i - 2)) % MOD;
				temp = (temp + dp[i - 1][j - 1][k]) % MOD;
				temp = (temp + dp[i - 1][j][k - 1]) % MOD;

				dp[i][j][k] = temp;
			}
		}
	}
	printf("%d\n", dp[n][l][r]);

	return 0;
}
