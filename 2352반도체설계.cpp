#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[40010];
int dp[40010];
int n, it, s;

int main() {
	freopen("input.txt", "r", stdin);
	memset(dp, -1, sizeof(dp));
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	for (int i = 0; i < n; i++) {
		if (dp[s] < a[i]) {
			s++;
			dp[s] = a[i];
		}
		it = lower_bound(dp, dp + s + 1, a[i] + 1) - dp;
		dp[it] = a[i];
	}
	printf("%d", s);
	
	return 0;
}

//�ð����⵵ n^2�����ϸ�(11053��) �ð��ʰ�
//nlogn���� �ؾ���