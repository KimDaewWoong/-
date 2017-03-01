#include<cstdio>
using namespace std;
int n, val, seg[400400], result[100010];

int update(int pos, int val, int node, int x, int y) {
	if (pos < x || pos > y) return seg[node];
	if (x == y) return seg[node] = val;
	int mid = (x + y) >> 1;
	return seg[node] = update(pos, val, node * 2, x, mid) + update(pos, val, node * 2 + 1, mid + 1, y);
}

int query(int val, int node, int x, int y) {
	if (x == y) return x;
	int mid = (x + y) >> 1;
	if (seg[node * 2] > val)
		return query(val, node * 2, x, mid);
	return query(val-seg[node*2], node * 2 + 1, mid + 1, y);
}

int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)	update(i, 1, 1, 1, n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &val);
		int index = query(val, 1, 1, n);
		result[index] = i;
		update(index, 0, 1, 1, n);
	}
	for (int i = 1; i <= n; i++)
		printf("%d\n", result[i]);

	return 0;
}