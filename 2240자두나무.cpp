#include<cstdio>
#include<algorithm>
using namespace std;
int T, W, maxResult;
int Dp[2][1010][33];
int jado[1010];
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &T, &W);

	for (int i = 1; i <= T; i++)
		scanf("%d", &jado[i]);

	for (int i = 1; i <= T; i++) {
		for (int k = 0; k <= W; k++){
			if (jado[i] == 1){
				Dp[0][i][k] = max(Dp[0][i][k], Dp[0][i - 1][k] + 1);
				Dp[0][i][k] = max(Dp[0][i][k], Dp[1][i - 1][k - 1] + 1);


				Dp[1][i][k] = max(Dp[1][i][k], Dp[1][i - 1][k]);
				Dp[1][i][k] = max(Dp[1][i][k], Dp[0][i - 1][k - 1]);
			}
			else{
				Dp[0][i][k] = max(Dp[0][i][k], Dp[0][i - 1][k]);
				Dp[0][i][k] = max(Dp[0][i][k], Dp[1][i - 1][k - 1]);

				Dp[1][i][k] = max(Dp[1][i][k], Dp[1][i - 1][k] + 1);
				Dp[1][i][k] = max(Dp[1][i][k], Dp[0][i - 1][k - 1] + 1);
			}
		}
	}
	for (int k = 0; k <= W; k++) {
		maxResult = max(maxResult, Dp[0][T][k]);
		maxResult = max(maxResult, Dp[1][T][k]);
	}
	printf("%d\n", maxResult);
	return 0;
}