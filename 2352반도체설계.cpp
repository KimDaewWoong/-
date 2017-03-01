#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[40010];
int dp[40010];
int n, it, s;

int main() {
	freopen("input.txt", "r", stdin);
	memset(dp, -1, sizeof(dp));
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	for (int i = 0; i < n; i++) {
		if (dp[s] < a[i]) {
			s++;
			dp[s] = a[i];
		}
		it = lower_bound(dp, dp + s + 1, a[i] + 1) - dp;
		dp[it] = a[i];
	}
	printf("%d", s);
	
	return 0;
}

//시간복잡도 n^2으로하면(11053번) 시간초과
//nlogn으로 해야함