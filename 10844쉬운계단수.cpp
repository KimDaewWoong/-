#include<cstdio>
#include<algorithm>
#define MOD 1000000000
typedef long long ll;
using namespace std;
ll dp[110][10];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i < 10; i++) {
		dp[1][i] = 1;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			if (j == 0) {
				dp[i][j] += (dp[i - 1][j + 1]) % MOD;
			}
			else if (j == 9) {
				dp[i][j] += (dp[i - 1][j - 1]) % MOD;
			}
			else {
				dp[i][j] += (dp[i - 1][j + 1] + dp[i - 1][j - 1]) % MOD;
			}
		}
	}
	ll res = 0;
	for (int i = 0; i < 10; i++) {
		res += (dp[n][i]) % MOD;
	}
	printf("%lld", res % MOD);
	return 0;
}

//Àç±Í
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//#define MOD 1000000000
//using namespace std;
//int dp[110][10];
//int n;
//int func(int pos, int q) {
//	if (q < 0 || q > 9) return 0;
//	if (pos == 1) return 1;
//	int& ret = dp[pos][q];
//	if (ret != -1) return ret;
//	ret = (func(pos - 1, q - 1) + func(pos - 1, q + 1)) % MOD;
//	return ret % MOD;
//}
//int main() {
//	memset(dp, -1, sizeof(dp));
//	scanf("%d", &n);
//	int ret = 0;
//	for (int i = 1; i < 10; i++) {
//		ret += (func(n, i)) % MOD;
//	}
//	printf("%d", ret);
//	return 0;
//}
