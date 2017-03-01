#include<cstdio>
#include<algorithm>
typedef long long ll;
using namespace std;

ll seg[4000040], n, m, k, a, b, c;

ll update(ll pos, ll val, ll node, ll x, ll y){
	if (pos < x || pos > y) return seg[node];
	if (x == y) return seg[node] = val;
	ll mid = (x + y) >> 1;
	return seg[node] = ((update(pos, val, node * 2, x, mid) % 1000000007) * (update(pos, val, node * 2 + 1, mid + 1, y) % 1000000007)) % 1000000007;
}

ll query(ll lo, ll hi, ll node, ll x, ll y) {
	if (lo > y || hi < x) return 1;
	if (lo <= x && hi >= y) return seg[node];
	ll mid = (x + y) >> 1;
	return ((query(lo, hi, node * 2, x, mid) % 1000000007) * (query(lo, hi, node * 2 + 1, mid + 1, y) % 1000000007)) % 1000000007;
}
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%lld %lld %lld", &n, &m, &k);
	for (int i = 1; i <= n; i++) {
		ll val;
		scanf("%lld", &val);
		update(i, val, 1, 1, n);
	}
	for (int i = 0; i < m + k; i++) {
		scanf("%lld %lld %lld", &a, &b, &c);
		if (a==1) {
			update(b, c, 1, 1, n);
		}
		else {
			printf("%lld\n", query(b, c, 1, 1, n));
		}
	}

	return 0;
}