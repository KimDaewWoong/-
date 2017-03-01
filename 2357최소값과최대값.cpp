#include<cstdio>
#include<algorithm>
#define PINF 9876543211
#define MINF -9876543211 
using namespace std;
int n, m, min_seg[400040], max_seg[400040];

int min_update(int pos, int val, int node, int x, int y) {
	if (pos < x || y < pos) 	return min_seg[node];
	if (x == y) return min_seg[node] = val;
	int mid = (x + y) >> 1;
	int lcv = min_update(pos, val, node * 2, x, mid);
	int rcv = min_update(pos, val, node * 2 + 1, mid + 1, y);
	return min_seg[node] = min(lcv, rcv);
}

int min_query(int lo, int hi, int node, int x, int y) {
	if (y < lo || hi < x) return PINF;
	if (lo <= x && y <= hi) return min_seg[node];
	int mid = (x + y) >> 1;
	int lcv = min_query(lo, hi, node * 2, x, mid);
	int rcv = min_query(lo, hi, node * 2 + 1, mid + 1, y);
	return min(lcv, rcv);
}

int max_update(int pos, int val, int node, int x, int y) {
	if (pos < x || y < pos) 	return max_seg[node];
	if (x == y) return max_seg[node] = val;
	int mid = (x + y) >> 1;
	int lcv = max_update(pos, val, node * 2, x, mid);
	int rcv = max_update(pos, val, node * 2 + 1, mid + 1, y);
	return max_seg[node] = max(lcv, rcv);
}

int max_query(int lo, int hi, int node, int x, int y) {
	if (y < lo || hi < x) return MINF;
	if (lo <= x && y <= hi) return max_seg[node];
	int mid = (x + y) >> 1;
	int lcv = max_query(lo, hi, node * 2, x, mid);
	int rcv = max_query(lo, hi, node * 2 + 1, mid + 1, y);
	return max(lcv, rcv);
}

int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		int val;
		scanf("%d", &val);
		min_update(i, val, 1, 0, n - 1);
		max_update(i, val, 1, 0, n - 1);
	}
	while (m--) {
		int lo, hi;
		scanf("%d %d", &lo, &hi);
		if (lo > hi) {
			swap(lo, hi);
		}
		printf("%d %d\n", min_query(lo - 1, hi - 1, 1, 0, n - 1), max_query(lo -1, hi -1, 1, 0, n-1));
	}

	return 0;
}