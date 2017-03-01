#include<cstdio>
using namespace std;
long long dp[35][35], k, sum;
int N, L;
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d %d %lld", &N, &L, &k);
	
	dp[0][0] = dp[1][0] = dp[1][1] = 1;

	for (int i = 2; i <= N; i++) {
		for (int j = 0; j <= L; j++) {
			if (j == 0) dp[i][j] = dp[i - 1][j];
			else dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
		}
	}
	while (N--) {
		sum = 0;
		for (int i = 0; i <= L; i++) sum += dp[N][i];
		if (sum < k) {
			printf("1");
			L--;
			k -= sum;
		}else {
			printf("0");
		}
	}
	return 0;
}