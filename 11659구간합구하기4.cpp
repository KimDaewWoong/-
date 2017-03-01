#include<cstdio>
using namespace std;
int n, m, seg[400040];

int update(int pos, int val, int node, int x, int y) {
	if (pos < x || pos > y) return seg[node];
	if (x == y) return seg[node] = val;
	int mid = (x + y) >> 1;
	return seg[node] = update(pos, val, node * 2, x, mid) + update(pos, val, node * 2 + 1, mid + 1, y);
}
int query(int lo, int hi, int node, int x, int y) {
	if (hi < x || y < lo) return 0;
	if (lo <= x && y <= hi) return seg[node];
	int mid = (x + y) >> 1;
	return query(lo, hi, node * 2, x, mid) + query(lo, hi, node * 2 + 1, mid + 1, y);
}
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		int val;
		scanf("%d", &val);
		update(i, val, 1, 1, n);
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", query(a, b, 1, 1, n));
	}

	return 0;
}