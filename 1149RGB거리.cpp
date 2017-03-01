#include<cstdio>
#include<algorithm>
using namespace std;

int a[1010][3];
int dp[1010][3];
int sum = 0;
int k = 0;
int N, C;
void color(int r, int g, int b) {

	dp[0][0] = r;
	dp[0][1] = g;
	dp[0][2] = b;

	for (int i = 1; i < k; ++i) {
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + a[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + a[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + a[i][2];
	}
	sum = min(min(dp[k - 1][0], dp[k - 1][1]), dp[k - 1][2]);
}

int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &N);
	while (N--) {
		for (int i = 0; i < 3; ++i) {
			scanf("%d", &C);
			a[k][i] = C;
		}
		k++;
	}
	color(a[0][0], a[0][1], a[0][2]);
	printf("%d", sum);
	return 0;
}