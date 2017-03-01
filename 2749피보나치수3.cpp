#include<cstdio>
const int mod = 1000000;
const int p = (mod / 10) * 15;
int f[p] = { 0, 1, };
int main() {

	for (int i = 2; i < p; i++) {
		f[i] = f[i - 1] + f[i - 2];
		f[i] %= mod;
	}
	long long n;
	scanf("%lld", &n);
	printf("%d", f[n%p]);

	return 0;
}