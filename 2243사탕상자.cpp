#include<cstdio>
#include<algorithm>
using namespace std;
int n, seg[4000100];
const int N = 1000000;
int update(int pos, int val, int node, int l, int r) {
	if (pos < l || pos > r) return seg[node];
	if (l == r) return seg[node] += val;
	int mid = (l + r) >> 1;
	return seg[node] = update(pos, val, node * 2, l, mid) + update(pos, val, node * 2 + 1, mid + 1, r);
}
int query(int val, int node, int l, int r) {
	if (l == r) return l;
	int mid = (l + r) >> 1;
	int p = seg[node * 2];
	if (val <= p) return query(val, node * 2, l, mid);
	else return query(val - p, node * 2 + 1, mid + 1, r);
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int d, a, b;
		scanf("%d %d", &d, &a);
		if (--d) {
			scanf("%d", &b);
			update(a, b, 1, 0, N - 1);
		}
		else {
			int k = query(a, 1, 0, N - 1);
			printf("%d\n", k);
			update(k, -1, 1, 0, N - 1);
		}
	}
	return 0;
}