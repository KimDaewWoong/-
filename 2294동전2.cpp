#include<cstdio>
#include<cstring>
#include<algorithm>
#define INF 0x3F3F3F3F
using namespace std;
int n, k;
int a[101];
int dp[10001];

int main() {
	freopen("input.txt", "r", stdin);
	memset(dp, 0x3F, sizeof(dp));
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)	scanf("%d", &a[i]);
	dp[0] = 0;
	for (int i = 0; i < n; i++) 
		for (int j = a[i]; j <= k; j++) 
			dp[j] = min(dp[j], dp[j - a[i]] + 1);
		
	
	if (dp[k] == INF) puts("-1");
	else printf("%d", dp[k]);
	return 0;
}