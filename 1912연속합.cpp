#include<cstdio>
#include<algorithm>
using namespace std;
int arr[100010], dp[100010], n;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &arr[i]);
	dp[n] = arr[n];
	int maxx = arr[n];
	for (int i = n - 1; i > 0; i--) {
		dp[i] = max(arr[i], arr[i] + dp[i + 1]);
		maxx = max(maxx, dp[i]);
	}
	printf("%d", maxx);
	return 0;
}