#include<cstdio>
#include<algorithm>
#define INF 987654321
using namespace std;
int n, m, seg[400010];
int update(int pos, int val, int node, int l, int r) {
	if (pos < l || pos > r) return seg[node];
	if (l == r) return seg[node] = val;
	int mid = (l + r) >> 1;
	return seg[node] = min(update(pos, val, node * 2, l, mid), update(pos, val, node * 2 + 1, mid + 1, r));
}
int query(int lo, int hi, int node, int l, int r) {
	if (l > hi || r < lo) return INF;
	if (hi >= r && lo <= l) return seg[node];
	int mid = (l + r) >> 1;
	return min(query(lo, hi, node * 2, l, mid), query(lo, hi, node * 2 + 1, mid + 1, r));
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int val;
		scanf("%d", &val);
		update(i, val, 1, 0, n - 1);
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int d, a, b;
		scanf("%d %d %d", &d, &a, &b);
		d--;
		if (d)
			printf("%d\n", query(a - 1, b - 1, 1, 0, n - 1));
		else
			update(a - 1, b, 1, 0, n - 1);
	}
	return 0;
}