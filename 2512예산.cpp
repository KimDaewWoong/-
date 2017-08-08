#include<cstdio>
#include<algorithm>
typedef long long ll;
using namespace std;
int n;
ll lo, hi, t;
ll arr[10010];
bool flag = false;
ll func(ll a) {
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		if (a > arr[i])
			sum += arr[i];
		else
			sum += a;
	}
	return sum <= t;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &arr[i]);
		if (hi < arr[i]) hi = arr[i];
	}
	scanf("%lld", &t);
	ll tmp = t;
	for (int i = 0; i < n; i++)
		tmp -= arr[i];
	if (tmp >= 0) {
		printf("%lld", hi);
		return 0;
	}
	ll maxx = hi;
	while (lo < hi) {
		ll mid = (lo + hi) >> 1;
		if (func(mid))
			lo = mid + 1;
		else
			hi = mid;
	}
	printf("%lld", lo - 1);

	return 0;
}