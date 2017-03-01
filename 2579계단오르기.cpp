#include<cstdio>
#include<cstring>
#include<algorithm>
#define INF -987654321
using namespace std;
//현재위치, 연속으로 올라간 계단 수
int dp[330][3], arr[330];
int n;
int func(int pos, int cnt) {
	if (cnt > 2) return INF;
	if (pos > n) return arr[pos];

	int& ret = dp[pos][cnt];
	if (ret != -1) return ret;

	return ret = max(func(pos + 1, cnt + 1), func(pos + 2, 1)) + arr[pos];
}
int main() {
	freopen("input.txt", "r", stdin);
	memset(dp, -1, sizeof(dp));
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &arr[i]);
	arr[n + 1] = INF;
	printf("%d", func(0, 0));
	return 0;
}