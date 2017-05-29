#include<cstdio>
#include<algorithm>
using namespace std;
int dp[1010][10];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < 10; i++) {
		dp[1][i] = 1;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int k = j; k >= 0; k--) {
				dp[i][j] += (dp[i - 1][k]) % 10007;
			}
		}
	}
	long long res = 0;
	for (int i = 0; i <= 9; i++) {
		res += (dp[n][i]) % 10007;
	}
	printf("%lld", res % 10007);
	return 0;
}
//Àç±Í
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//#define MOD 10007
//using namespace std;
//int dp[1010][10];
//int n;
//int func(int pos, int q) {
//	if (pos == 1) return 1;
//	int& ret = dp[pos][q];
//	if (ret != -1) return ret;
//	ret = 0;
//	for (int i = q; i >= 0; i--) {
//		ret += (func(pos - 1, i)) % MOD;
//	}
//	return ret % MOD;
//}
//int main() {
//	memset(dp, -1, sizeof(dp));
//	scanf("%d", &n);
//	printf("%d", func(n + 1, 9));
//	return 0;
//}