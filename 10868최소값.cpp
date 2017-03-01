#include<cstdio>
#include<algorithm>
#define INF 9876543211
using namespace std;
int n, m, seg[400040];

int update(int pos, int val, int node, int x, int y) {
	if (pos < x || y < pos)	return seg[node];
	if (x == y) return seg[node] = val;
	int mid = (x + y) >> 1;
	return seg[node] = min(update(pos, val, node * 2, x, mid),
		update(pos, val, node * 2 + 1, mid + 1, y));
}

int query(int lo, int hi, int node, int x, int y) {
	if(y < lo || hi < x) return INF;
	if (lo <= x && y <= hi) return seg[node];
	int mid = (x + y) >> 1;
	return min(query(lo, hi, node * 2, x, mid),
		query(lo, hi, node * 2 + 1, mid + 1, y));
}

int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		int val;
		scanf("%d", &val);
		//pos, val, node, min_index, max_index
		update(i, val, 1, 0, n - 1);
	}
	while (m--) {
		int lo, hi;
		scanf("%d %d", &lo, &hi);
		if (lo > hi) swap(lo, hi);
		//lo, hi, ndoe, min_index, max_index
		printf("%d\n", query(lo - 1, hi - 1, 1, 0, n - 1));
	}
	return 0;
}