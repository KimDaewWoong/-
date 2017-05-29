#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int  t, n, m, k;
int dp[310][310];
int arr[15];
int main() {
	scanf("%d", &t);
	while (t--) {
		memset(dp, 0, sizeof(dp));
		memset(arr, 0, sizeof(arr));
		scanf("%d %d", &m, &n);
		k = 0;
		arr[1] = 1;
		for (int i = 1; i <= n; i <<= 1) k++;
		for (int i = 2; i <= k; i++) {
			arr[i] = arr[i - 1] * 2;
		}

		dp[0][0] = 1;
		for (int i = 1; i <= k; i++) dp[i][0] = 1;

		for (int i = 1; i <= k; i++) {	//종류
			for (int j = 1; j <= n; j++){	//원하는 값
				for (int h = 0; h <= m; h++) {	//각 개수
					if ((arr[i] * h) > j) break;	//개수보다 커지면 끝
					dp[i][j] += dp[i - 1][j - (arr[i] * h)];
				}
			}
		}


		printf("%d\n", dp[k][n]);
	}
	return 0;
}