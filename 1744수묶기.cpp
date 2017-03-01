#include<cstdio>
#include<cstring>
#include<algorithm>
#define INF 0xF3F3F3F3
using namespace std;
int n;
int a[10010], dp[10010];
int func(int pos) {
	int& ret = dp[pos];
	if (ret != INF) return ret;
	if (pos == 0) return ret = a[0];
	return ret = max(a[pos] + func(pos - 1), a[pos] * a[pos - 1] + func(pos - 2));
}
int main() {	
	memset(dp, 0xF3, sizeof(dp));
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	sort(a, a + n);
	printf("%d\n", func(n - 1));
}