#include<cstdio>
#include<algorithm>
typedef long long ll;
using namespace std;
int n, m;
ll lo, hi = 1e10;
ll arr[10010];
ll func(ll a) {
	ll sum = 0;
	for (int i = 0; i < n; i++)
		sum += (arr[i] / a);

	return sum >= m;
}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%lld", &arr[i]);

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