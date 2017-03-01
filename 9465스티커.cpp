#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n, arr[2][100010],dp[2][100010];
int func(int i, int j) {
	if (j <= 0) return arr[i][j];
	int& ret = dp[i][j];
	if (ret != -1) return ret;
	return ret = max(func(i^1, j-2) ,max(func(i, j-2), func(i^1, j-1)))+arr[i][j];
}
int main() {
	freopen("input.txt", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--) {
		memset(dp, -1, sizeof(dp));
		memset(arr, 0, sizeof(arr));
		scanf("%d", &n);
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < n; ++j)
				scanf("%d", &arr[i][j]);

		printf("%d\n", max(func(0, n-1), func(1, n-1)));
	}
}