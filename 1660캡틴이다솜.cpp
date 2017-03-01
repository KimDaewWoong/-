#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int temp[125], arr[125], dp[300010], n;

int main() {
	memset(dp, 0x3F, sizeof(dp));
	scanf("%d", &n);
	temp[1] = arr[1] = 1;
	for (int i = 2; i <= 122; i++) {
		temp[i] = temp[i - 1] + i;
		arr[i] = temp[i] + arr[i-1];
	}

	dp[0] = 0;
	for (int i = 1; i <= 122; i++) {
		for (int j = arr[i]; j <= n; j++) {
			dp[j] = min(dp[j], dp[j - arr[i]] + 1);
		}
	}
	printf("%d", dp[n]);
	return 0;
}