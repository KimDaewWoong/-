#include<cstdio>
#include<algorithm>
using namespace std;
const int MAX = 4587520;
const int INF = 987654321;
int max_seg[MAX * 4], min_seg[MAX * 4], max_lazy[MAX * 4], min_lazy[MAX * 4];
int c, n, o;
char order[20];
//MAX
void maxlazy(int node, int l, int r) {
	if (max_lazy[node]) {
		max_seg[node] += max_lazy[node];
		if (l != r) {
			max_lazy[node * 2] += max_lazy[node];
			max_lazy[node * 2 + 1] += max_lazy[node];
		}
		max_lazy[node] = 0;
	}
}
int max_update(int lo, int hi, int val, int node, int l, int r) {
	maxlazy(node, l, r);
	if (lo > r || hi < l) return max_seg[node];
	if (lo <= l && hi >= r) {
		max_seg[node] += val;
		if (l != r) {
			max_lazy[node * 2] += val;
			max_lazy[node * 2 + 1] += val;
		}
		return max_seg[node];
	}
	int mid = (l + r) >> 1;
	return max_seg[node] = max(max_update(lo, hi, val, node * 2, l, mid), max_update(lo, hi, val, node * 2 + 1, mid + 1, r));
}
int max_query(int lo, int hi, int node, int l, int r) {
	maxlazy(node, l, r);
	if (lo > r || hi < l) return 0;
	if (lo <= l&&hi >= r) return max_seg[node];
	int mid = (l + r) >> 1;
	return max(max_query(lo, hi, node * 2, l, mid), max_query(lo, hi, node * 2 + 1, mid + 1, r));
}
//MIN
void minlazy(int node, int l, int r) {
	if (min_lazy[node]) {
		min_seg[node] += min_lazy[node];
		if (l != r) {
			min_lazy[node * 2] += min_lazy[node];
			min_lazy[node * 2 + 1] += min_lazy[node];
		}
		min_lazy[node] = 0;
	}
}
int min_update(int lo, int hi, int val, int node, int l, int r) {
	minlazy(node, l, r);
	if (lo > r || hi < l) return min_seg[node];
	if (lo <= l && hi >= r) {
		min_seg[node] += val;
		if (l != r) {
			min_lazy[node * 2] += val;
			min_lazy[node * 2 + 1] += val;
		}
		return min_seg[node];
	}
	int mid = (l + r) >> 1;
	return min_seg[node] = min(min_update(lo, hi, val, node * 2, l, mid), min_update(lo, hi, val, node * 2 + 1, mid + 1, r));
}
int min_query(int lo, int hi, int node, int l, int r) {
	minlazy(node, l, r);
	if (lo > r || hi < l) return INF;
	if (lo <= l&&hi >= r) return min_seg[node];
	int mid = (l + r) >> 1;
	return min(min_query(lo, hi, node * 2, l, mid), min_query(lo, hi, node * 2 + 1, mid + 1, r));
}
int main() {
	freopen("input.txt", "r", stdin);
	//c = core, n = number, o = operation
	scanf("%d%d%d", &c, &n, &o);

	for (int i = 0; i < o; i++) {
		int a, b, d;
		scanf(" %s", order);
		if (order[0] == 's') {
			scanf("%d", &a);
			printf("%d\n", max_query(a, a, 1, 0, c - 1));
		}
		else if (order[0] == 'g') {
			scanf("%d %d %d", &a, &b, &d);
			if (d > 0) {
				int q = max_query(a, b, 1, 0, c - 1);
				if (q + d > n) {
					max_update(a, b, n - q, 1, 0, c - 1);
					min_update(a, b, n - q, 1, 0, c - 1);
					printf("%d\n", n - q);
				}
				else {
					max_update(a, b, d, 1, 0, c - 1);
					min_update(a, b, d, 1, 0, c - 1);
					printf("%d\n", d);
				}
			}
			else {
				int q = min_query(a, b, 1, 0, c - 1);
				if (q + d < 0) {
					max_update(a, b, -q, 1, 0, c - 1);
					min_update(a, b, -q, 1, 0, c - 1);
					printf("%d\n", -q);
				}
				else {
					max_update(a, b, d, 1, 0, c - 1);
					min_update(a, b, d, 1, 0, c - 1);
					printf("%d\n", d);
				}
			}
		}
		else {
			scanf("%d %d", &a, &b);
			int q = max_query(a, a, 1, 0, c - 1);
			if (q + b > n) {
				max_update(a, a, n - q, 1, 0, c - 1);
				min_update(a, a, n - q, 1, 0, c - 1);
				printf("%d\n", n - q);
			}
			else if (q + b < 0) {
				max_update(a, a, -q, 1, 0, c - 1);
				min_update(a, a, -q, 1, 0, c - 1);
				printf("%d\n", -q);
			}
			else {
				max_update(a, a, b, 1, 0, c - 1);
				min_update(a, a, b, 1, 0, c - 1);
				printf("%d\n", b);
			}
		}
	}

	return 0;
}