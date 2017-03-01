#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int a[10010];
int dp[10010][3]; //현재위치, 연속으로먹은 잔 수
int n, sum;
int func(int pos, int cnt) {
	//기저사례
	if (cnt >= 3) return -987654321;
	if (pos == n) return 0;
	//예외처리
	int& ret = dp[pos][cnt];
	if (ret != -1) return ret;

	return ret = max(func(pos + 1, 0), (a[pos] + func(pos + 1, cnt + 1)));
}

int main() {
	freopen("input.txt", "r", stdin);
	memset(dp, -1, sizeof(dp));
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	printf("%d", func(0, 0));
	return 0;
}