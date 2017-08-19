#include<cstdio>
#include<algorithm>
typedef long long ll;
using namespace std;
const ll MAX = 500000;
ll n, seg[MAX * 4], arr[MAX], ranc[MAX];
ll update(ll pos, ll val, ll node, ll l, ll r) {
	if (pos < l || pos > r) return seg[node];
	if (l == r) return seg[node] = val;
	ll mid = (l + r) >> 1;
	return seg[node] = update(pos, val, node * 2, l, mid) + update(pos, val, node * 2 + 1, mid + 1, r);
}
ll query(ll lo, ll hi, ll node, ll l, ll r) {
	if (lo > r || hi < l) return 0;
	if (lo <= l && hi >= r) return seg[node];
	ll mid = (l + r) >> 1;
	return query(lo, hi, node * 2, l, mid) + query(lo, hi, node * 2 + 1, mid + 1, r);
}
int main() {
	scanf("%lld", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &arr[i]);
		ranc[i] = arr[i];
	}
	sort(ranc, ranc + n);
	for (int i = 0; i < n; i++) {
		ll idx = lower_bound(ranc, ranc + n, arr[i]) - ranc;
		printf("%lld\n", query(idx, MAX - 1LL, 1LL, 0LL, MAX - 1LL) + 1LL);
		update(idx, 1LL, 1LL, 0LL, MAX - 1LL);
	}


	return 0;
}