#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
typedef long long ll;
using namespace std;
			//seg, 초기 적설량, 적설량, query, 4th
ll n, m, N, seg[800080], s[100010], t[100010], q[3][100010], fourth[400040];
vector<ll> vt, arr;
ll update(ll pos, ll val, ll node, ll l, ll r) {
	if (pos < l || pos > r) return seg[node];
	if (l == r) return seg[node] += val;
	ll mid = (l + r) >> 1;
	return seg[node] = update(pos, val, node * 2, l, mid) + update(pos, val, node * 2 + 1, mid + 1, r);
}
ll sum(ll lo, ll hi, ll node, ll l, ll r) {
	if (lo > r || hi < l) return 0;
	if (lo <= l && hi >= r) return seg[node];
	ll mid = (l + r) >> 1;
	return sum(lo, hi, node * 2, l, mid) + sum(lo, hi, node * 2 + 1, mid + 1, r);
}
ll find(ll val, ll node, ll l, ll r) {
	if (l == r) return l;
	ll p = seg[node * 2];
	ll mid = (l + r) >> 1;
	if (val <= p) find(val, node * 2, l, mid);
	else find(val - p, node * 2 + 1, mid + 1, r);
}
ll getpos(ll x) {
	return lower_bound(arr.begin(), arr.end(), x) - arr.begin();
}
int main() {
	scanf("%lld %lld", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &s[i]);
		t[i] = s[i];
		vt.push_back(s[i]);
	}
	for (int i = 0; i < m; i++) {
		ll d, a, b;
		scanf("%lld %lld", &d, &a);
		q[0][i] = d;
		if (d == 4) q[1][i] = a;
		else {
			scanf("%lld", &b);
			if (d == 1) {
				s[a] += b;
				vt.push_back(s[a]);
			}
			else if (d == 2) {
				s[a] -= b;
				vt.push_back(s[a]);
			}
			else {
				vt.push_back(a);
				vt.push_back(b);
			}
			q[1][i] = a;
			q[2][i] = b;
		}
	}
	sort(vt.begin(), vt.end());
	vt.erase(unique(vt.begin(), vt.end()), vt.end());

	arr.push_back(-1);
	for (int i = 1; i <= vt.size(); i++) {
		arr.push_back(vt[i - 1]);
		fourth[i] = vt[i - 1];
	}
	N = vt.size();

	for (int i = 1; i <= n; i++) update(getpos(t[i]), 1, 1, 1, N);

	for (int i = 0; i < m; i++) {
		ll& idx = t[q[1][i]];
		if (q[0][i] == 1) {
			update(getpos(idx), -1, 1, 1, N);
			idx += q[2][i];
			update(getpos(idx), 1, 1, 1, N);
		}
		else if (q[0][i] == 2) {
			update(getpos(idx), -1, 1, 1, N);
			idx -= q[2][i];
			update(getpos(idx), 1, 1, 1, N);
		}
		else if (q[0][i] == 3) printf("%lld\n", sum(getpos(q[1][i]), getpos(q[2][i]), 1, 1, N));
		else printf("%lld\n", fourth[find(n + 1 - q[1][i], 1, 1, N)]);
	}
	return 0;
}