#include<cstdio>
#include<algorithm>
#define MOD 1000000000
typedef long long ll;
using namespace std;
ll dp[110][10][1 << 10], bit[10] = { 1, };
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i < 10; i++) {
		dp[1][i][1 << i] = 1LL;
		bit[i] = bit[i - 1] << 1LL;
	}

	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int k = 1; k < (1 << 10); k++) {
				if (j)
					dp[i + 1][j][k | bit[j]] = (dp[i + 1][j][k | bit[j]] + dp[i][j - 1][k]) % MOD;
				if (j<9)
					dp[i + 1][j][k | bit[j]] = (dp[i + 1][j][k | bit[j]] + dp[i][j + 1][k]) % MOD;
			}
		}
	}
	ll res = 0;
	for (int i = 0; i < 10; i++)
		res = (res + dp[n][i][(1 << 10) - 1]) % MOD;

	printf("%lld", res);
	return 0;
}