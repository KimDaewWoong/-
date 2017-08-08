#include<cstdio>
#include<algorithm>
typedef long long ll;
using namespace std;
int n, m;
ll lo, hi;
ll arr[200010];
ll func(ll a) {
	ll b = arr[0], cnt = 1;
	for (int i = 1; i < n; i++) {
		if (arr[i] - b >= a) {
			cnt++;
			b = arr[i];
		}
	}
	return cnt >= m;
}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%lld", &arr[i]);
	sort(arr, arr + n);
	hi = arr[n - 1] - arr[0];
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