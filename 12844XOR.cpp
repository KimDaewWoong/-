#include<cstdio>
#include<algorithm>
#define MAXX 2000020
using namespace std;
int n, m, t, a, b, c;
int tree[MAXX], lazy[MAXX];
int init(int pos, int val, int node, int left, int right) {
	if (pos < left || right < pos) return tree[node];
	if (left == right) return tree[node] = val;
	int mid = (left + right) >> 1;
	return tree[node] = init(pos, val, node * 2, left, mid) ^ init(pos, val, node * 2 + 1, mid + 1, right);
}
void update_lazy(int node, int left, int right) {
	if (lazy[node]) {
		tree[node] ^= ((right - left + 1) & 1)*lazy[node];
		if (left != right) {
			lazy[node * 2] ^= lazy[node];
			lazy[node * 2 + 1] ^= lazy[node];
		}
		lazy[node] = 0;
	}
}
void update(int lo, int hi, int val, int node, int left, int right) {
	update_lazy(node, left, right);
	if (hi < left || right < lo) return;
	if (lo <= left && right <= hi) {
		tree[node] ^= ((right - left + 1) & 1)*val;
		if (left != right) {
			lazy[node * 2] ^= val;
			lazy[node * 2 + 1] ^= val;
		}
		return;
	}
	int mid = (left + right) >> 1;
	update(lo, hi, val, node * 2, left, mid);
	update(lo, hi, val, node * 2 + 1, mid + 1, right);
	tree[node] = tree[node * 2] ^ tree[node * 2 + 1];
}
int query(int lo, int hi, int node, int left, int right) {
	update_lazy(node, left, right);
	if (hi<left || lo>right) return 0;
	if (lo <= left && hi >= right) return tree[node];
	int mid = (left + right) >> 1;
	int lcv = query(lo, hi, node * 2, left, mid);
	int rcv = query(lo, hi, node * 2 + 1, mid + 1, right);
	return lcv^rcv;
}
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int val;
		scanf("%d", &val);
		init(i, val, 1, 0, n - 1);
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &t, &a, &b);
		if (a > b) swap(a, b);
		if (t & 2) {
			printf("%d\n", query(a, b, 1, 0, n - 1));
		}
		else {
			scanf("%d", &c);
			update(a, b, c, 1, 0, n - 1);
		}
	}
	return 0;
}