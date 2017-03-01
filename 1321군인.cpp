#include<cstdio>
#include<algorithm>
using namespace std;
int n, m, valBank[500050],seg[2000200];

int update(int pos, int val, int node, int x, int y) {
	if (pos<x || pos>y) return seg[node];
	if (x == y) return seg[node] = val;
	int mid = (x + y) >> 1;
	return seg[node] = update(pos, val, node * 2, x, mid) + update(pos, val, node * 2 + 1, mid + 1, y);
}

int query(int val, int node, int x, int y) {
	if (x == y) return x;
	int mid = (x + y) >> 1;
	if (seg[node * 2] >= val) 
		return query(val, node * 2, x, mid);
	return query(val - seg[node * 2], node * 2 + 1, mid + 1, y);
}

int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int val;
		scanf("%d", &val);
		update(i, val, 1, 0, n - 1);
		valBank[i] = val;
	}
	scanf("%d", &m);
	while (m--) {
		int a, b, c, d;
		scanf("%d", &a);
		if (a == 1) {
			scanf("%d %d", &b, &c);
			update(b-1, valBank[b-1] + c, 1, 0, n - 1);
			valBank[b-1] += c;
		}
		else {
			scanf("%d", &d);
			printf("%d\n", query(d, 1, 0, n-1)+1);
		}
	}
	return 0;
}