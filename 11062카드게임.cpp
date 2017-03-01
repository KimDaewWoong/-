#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t, l, card[1010];
int dp[1010][1010][2];

int game(int i, int j, int flag) {
	if (i == j) {
		if (flag) return 0;
		else return card[i];
	}
	int& ret = dp[i][j][flag];
	if (ret != -1) return ret;
	ret = 0;
	if (!flag)
		ret = max(game(i + 1, j, !flag) + card[i], game(i, j - 1, !flag) + card[j]);
	else
		ret = min(game(i + 1, j, !flag), game(i, j - 1, !flag));
	return ret;
}
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &t);
	while (t--) {
		memset(dp, -1, sizeof(dp));
		scanf("%d", &l);
		for (int i = 0; i < l; i++) scanf("%d", &card[i]);
		printf("%d\n", game(0, l - 1, 0));
	}
	return 0;
}