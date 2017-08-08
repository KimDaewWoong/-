#include<cstdio>
#include<algorithm>
typedef long long ll;
using namespace std;
int n, m;
ll lo, hi = 1e9;
ll arr[100010];
ll func(ll a) {
	ll sum = 0, cnt = 1;
	for (int i = 0; i < n; i++) {
		if (sum + arr[i] > a) {
			sum = 0;
			cnt++;
		}
		sum += arr[i];
	}
	return cnt > m;
}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &arr[i]);
		if (lo < arr[i]) lo = arr[i];
	}
	while (lo < hi) {
		ll mid = (lo + hi) >> 1;
		if (func(mid))
			lo = mid + 1;
		else
			hi = mid;
	}
	printf("%lld", lo);

	return 0;
}