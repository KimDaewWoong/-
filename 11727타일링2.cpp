#include<cstdio>
#include<cstring>
#include<algorithm>
#define MOD 10007
using namespace std;
int dp[1010];
int n;
int func(int pos) {
	if (pos == 0 || pos == 1) return 1;
	int& ret = dp[pos];
	if (ret != -1) return ret;
	ret = 0;
	return ret = (func(pos - 1) + 2 * (func(pos - 2))) % MOD;
}
int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d", &n);
	printf("%d", func(n));
	return 0;
}