#include<cstdio>
#include<algorithm>
using namespace std;
int seg[2002000], lazy[2002000];
int init(int pos, int val, int node, int l, int r) {
	if (pos<l || pos>r) return seg[node];
	if (l == r) return seg[node] = val;
	int mid = (l + r) >> 1;
	return seg[node] = init(pos, val, node * 2, l, mid) ^ init(pos, val, node * 2 + 1, mid + 1, r);
}
void lazy_func(int node, int l, int r) {
	if (lazy[node]) {
		seg[node] ^= ((r - l + 1) & 1)*lazy[node];
		if (l != r) {
			lazy[node * 2] ^= lazy[node];
			lazy[node * 2 + 1] ^= lazy[node];
		}
		lazy[node] = 0;
	}
}
int update(int lo, int hi, int val, int node, int l, int r) {
	lazy_func(node, l, r);
	if (lo > r || l > hi) return seg[node];
	if (lo <= l && hi >= r) {
		seg[node] ^= ((r - l + 1) & 1)*val;
		if (l != r) {
			lazy[node * 2] ^= val;
			lazy[node * 2 + 1] ^= val;
		}
		return seg[node];
	}
	int mid = (l + r) >> 1;
	return seg[node] = update(lo, hi, val, node * 2, l, mid) ^ update(lo, hi, val, node * 2 + 1, mid + 1, r);
}
int query(int lo, int hi, int node, int l, int r) {
	lazy_func(node, l, r);
	if (lo > r || l > hi) return 0;
	if (lo <= l && hi >= r) return seg[node];
	int mid = (l + r) >> 1;
	return query(lo, hi, node * 2, l, mid) ^ query(lo, hi, node * 2 + 1, mid + 1, r);
}
int main() {
	int n, m;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int val;
		scanf("%d", &val);
		init(i, val, 1, 0, n - 1);
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int t, a, b, c;
		scanf("%d%d%d", &t, &a, &b);
		if (a > b) swap(a, b);
		if (--t)
			printf("%d\n", query(a, b, 1, 0, n - 1));
		else {
			scanf("%d", &c);
			update(a, b, c, 1, 0, n - 1);
		}
	}
	return 0;
}