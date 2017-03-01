#include<cstdio>
#include<algorithm>
using namespace std;
int p[1010];
int dp[1010];
int N;

int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%d", &p[i]);
	dp[1] = p[1];
	for (int i = 1; i <= N; i++) {
		for (int j = i; j <= N; j++) {
			dp[j] = max(dp[j], p[i] + dp[j - i]);
		}
	}
	printf("%d", dp[N]);
	return 0;
}