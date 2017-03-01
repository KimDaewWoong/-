#include<cstdio>
using namespace std;
int n, k, s;
int a[101];
int dp[10001];

int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)	scanf("%d", &a[i]);
	dp[0] = 1;
	for (int i = 0; i < n; i++)
		for (int j = a[i]; j <= k; j++)
			dp[j] += dp[j - a[i]];

	printf("%d", dp[k]);
	return 0;
}