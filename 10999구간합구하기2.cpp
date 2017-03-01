#include<cstdio>
using namespace std;
typedef long long ll;
ll n, m, k, seg[4000040], lazy[4000040];

ll init(ll pos, ll val, ll node, ll x, ll y) {
	if (pos<x || pos>y) return seg[node];
	if (x == y) return seg[node] = val;
	ll mid = (x + y) >> 1;
	return seg[node] = init(pos, val, node * 2, x, mid) + init(pos, val, node * 2 + 1, mid + 1, y);
}
void update_lazy(ll node, ll x, ll y) {
	if (lazy[node]) {
		seg[node] += (y - x + 1) * lazy[node];
		if (x != y) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}
ll update(ll lo, ll hi, ll val, ll node, ll x, ll y) {
	update_lazy(node, x, y);
	if (hi < x || lo>y) return seg[node];
	if (lo <= x && hi >= y) {
		lazy[node] += val;
		update_lazy(node, x, y);
		return seg[node];
	}
	ll mid = (x + y) >> 1;
	return seg[node] = update(lo, hi, val, node * 2, x, mid) + update(lo, hi, val, node * 2 + 1, mid + 1, y);
}
ll query(ll lo, ll hi, ll node, ll x, ll y) {
	update_lazy(node, x, y);
	if (y < lo || hi < x) return 0;
	if (lo <= x && y <= hi) return seg[node];
	ll mid = (x + y) >> 1;
	return query(lo, hi, node * 2, x, mid) + query(lo, hi, node * 2 + 1, mid + 1, y);
}

int main() {
	freopen("input.txt", "r", stdin);
	scanf("%lld%lld%lld", &n, &m, &k);
	for (ll i = 1; i <= n; i++) {
		ll val;
		scanf("%lld", &val);
		init(i, val, 1, 1, n);
	}
	ll a, b, c;
	for (ll i = 0; i < m + k; i++) {
		scanf("%lld%lld%lld", &a, &b, &c);
		if (a == 1) {
			ll d;
			scanf("%lld", &d);
			update(b, c, d, 1, 1, n);
		}
		else {
			printf("%lld\n", query(b, c, 1, 1, n));
		}
	}

	return 0;
}