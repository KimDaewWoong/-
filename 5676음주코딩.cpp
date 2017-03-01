#include<cstdio>
#include<algorithm>
using namespace std;
int n, k, seg[4000040];

int update(int pos, int val, int node, int x, int y) {
	if (pos<x || pos>y) return seg[node];
	if (x == y) return seg[node] = val;
	int mid = (x + y) >> 1;
	return seg[node] = update(pos, val, node * 2, x, mid) * update(pos, val, node * 2 + 1, mid + 1, y);
}

int query(int lo, int hi, int node, int x, int y) {
	if (lo > y || hi < x) return 1;
	if (lo <= x && hi >= y) return seg[node];
	int mid = (x + y) >> 1;
	return query(lo, hi, node * 2, x, mid) * query(lo, hi, node * 2 + 1, mid + 1, y);
}

int main() {
	freopen("input.txt", "r", stdin);
	while(scanf("%d %d", &n, &k) != EOF) {
		for (int i = 0; i < n; i++) {
			int val;
			scanf("%d", &val);
			if (val > 0) {
				update(i, 1, 1, 0, n - 1);
			}
			else if (val < 0) {
				update(i, -1, 1, 0, n - 1);
			}
			else {
				update(i, 0, 1, 0, n - 1);
			}
		}
		char a; int b, c;
		while (k--) {
			getchar();
			scanf("%c %d %d", &a, &b, &c);
			if (a == 'C') {
				if (c > 0) {
					update(b-1, 1, 1, 0, n - 1);
				}
				else if (c < 0) {
					update(b-1, -1, 1, 0, n - 1);
				}
				else {
					update(b-1, 0, 1, 0, n - 1);
				}
			}
			else {
				int result = query(b-1, c-1, 1, 0, n - 1);
				if (result > 0) {
					printf("+");
				}
				else if (result < 0) {
					printf("-");
				}
				else {
					printf("0");
				}
			}
		}
		puts("");
	}

	return 0;
}