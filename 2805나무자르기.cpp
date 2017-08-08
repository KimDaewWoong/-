#include<cstdio>
#include<algorithm>
typedef long long ll;
using namespace std;
int n, m;
ll arr[1000010];
ll func(ll a) {
	ll sum = 0;
	for (int i = 0; i < n; i++) sum += max(0ll, arr[i] - a);
	return sum < m;
}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) scanf("%lld", &arr[i]);

	ll lo = 0;
	ll hi = 1000000001;

	while (lo < hi) {
		ll mid = (lo + hi) >> 1;
		if (func(mid))
			hi = mid;
		else lo = mid + 1;
	}
	printf("%lld", lo - 1);

	return 0;
}