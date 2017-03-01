//ÀÌºÐÅ½»ö
#include<cstdio>
#include<algorithm>
using namespace std;
int n, k, lo, hi, mid;
int main() {
	scanf("%d %d", &n, &k);
	lo = 1; hi = k;
	while (lo <= hi) {
		long long c = 0;
		mid = (lo + hi) / 2;
		for (int i = 1; i <= n; i++) c += min(n, mid / i);
		if (c < k) lo = mid + 1;
		else hi = mid - 1;
	}
	printf("%d", lo);
	return 0;
}