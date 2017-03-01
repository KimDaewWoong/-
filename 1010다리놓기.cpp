#include<cstdio>
int t, n, m;
int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);
		long long a = 1;
		for (int i = 1; i <= n; i++)
			a = a*(m - i + 1) / i;
		printf("%lld\n", a);
	}
	return 0;
}