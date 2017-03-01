#include<cstdio>
#include<cstring>
using namespace std;
int t, n, m, seg[800080], disk[200010];
int update(int pos, int val, int node, int x, int y) {
	if (pos<x || pos>y) return seg[node];
	if (x == y) return seg[node] = val;
	int mid = (x + y) >> 1;
	return seg[node] = update(pos, val, node * 2, x, mid) + update(pos, val, node * 2 + 1, mid + 1, y);
}
int query(int lo, int hi, int node, int x, int y) {
	if (lo > y || hi < x) return 0;
	if (lo <= x && hi >= y) return seg[node];
	int mid = (x + y) >> 1;
	return query(lo, hi, node * 2, x, mid) + query(lo, hi, node * 2 + 1, mid + 1, y);
}
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &t);
	while (t--) {
		memset(seg, 0, sizeof(seg));
		memset(disk, 0, sizeof(disk));

		scanf("%d%d", &n, &m);
		for (int i = m + 1; i <= n + m; i++){
			update(i, 1, 1, 1, n+m);
			disk[i - m] = i;
		}
		int idx = m;
		for (int i = 0; i < m; i++) {
			int pos;
			scanf("%d", &pos);
			printf("%d ", query(1, disk[pos]-1, 1, 1, n+m));
			update(disk[pos], 0, 1, 1, n+m);
			disk[pos] = idx--;
			update(disk[pos], 1, 1, 1, n+m);
		}
		puts("");
	}
	return 0;
}