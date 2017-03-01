#include <cstdio>
using namespace std;

long long dp[22];

int main() {
	int t;
	scanf("%d", &t);

	dp[2] = 1;
	for (int i = 3; i <= 20; i++) {
		dp[i] = (i - 1)*(dp[i - 1] + dp[i - 2]);
	}
	while (t--) {
		long long a;
		scanf("%lld", &a);
		printf("%lld\n", dp[a]);
	}
	return 0;
}