//파라메트릭 서치
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define INF 987654321;
int dp[20][1000][1000];
int n, a[30], hi, lo, mid;
int func(int, int, int);
int main() {
	freopen("input.txt", "r", stdin);
	memset(dp, -1, sizeof(dp));
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	hi = 1000;
	while (lo < hi) {
		mid = (lo + hi) >> 1;
		if (mid < func(0, mid, mid)) {
			lo = mid + 1;
		}
		else {
			hi = mid;
		}
	}
	printf("%d\n", lo);
	return 0;
}
int func(int pos, int x, int y){
	if (pos > n) return 0;
	if (x < 0 || y < 0) return INF;
	int &ret = dp[pos][x][y];
	if (ret != -1) return ret;
	return ret = min(func(pos + 1, x - a[pos], y), min(func(pos + 1, x, y - a[pos]), func(pos + 1, x, y) + a[pos]));
}