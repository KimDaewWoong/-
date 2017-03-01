#include<cstdio>
using namespace std;
typedef long long ll;
int n, m, k;
ll seg[4000010];
ll update(int pos, ll val, int node, int left, int right) {
	if (pos < left || right < pos) return seg[node];
	if (left == right) return seg[node] = val;
	int mid = (left + right) >> 1;
	ll lcv = update(pos, val, node * 2, left, mid);
	ll rcv = update(pos, val, node * 2 + 1, mid + 1, right);
	return seg[node] = lcv + rcv;
}
ll sum(int lo, int hi, int node, int left, int right) {
	if (hi < left || right < lo) return 0;
	if (lo <= left && right <= hi) return seg[node];
	int mid = (left + right) >> 1;
	ll lcv = sum(lo, hi, node * 2, left, mid);
	ll rcv = sum(lo, hi, node * 2 + 1, mid + 1, right);
	return lcv + rcv;
}
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < n; i++) {
		ll val;
		scanf("%lld", &val);
		update(i, val, 1, 0, n - 1);
	}
	for (int i = 0; i < m + k; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if (a >> 1) printf("%lld\n", sum(b - 1, c - 1, 1, 0, n - 1));
		else update(b - 1, c, 1, 0, n - 1);
	}
	return 0;
}