#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n, seg[400010], arr[100100], order[100100], res[100100];
int update(int pos, int val, int node, int l, int r) {
	if (pos<l || pos>r) return seg[node];
	if (l == r) return seg[node] = val;
	int mid = (l + r) >> 1;
	return seg[node] = update(pos, val, node * 2, l, mid) + update(pos, val, node * 2 + 1, mid + 1, r);
}
int query(int val, int node, int l, int r) {
	if (l == r) return l;
	int mid = (l + r) >> 1;
	if (seg[node * 2] >= val) query(val, node * 2, l, mid);
	else query(val - seg[node * 2], node * 2 + 1, mid + 1, r);
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		update(i, 1, 1, 0, n - 1);
	}
	sort(arr, arr + n);
	for (int i = 0; i < n; i++) scanf("%d", &order[i]);
	for (int i = n - 1; i >= 0; i--) {
		int k = query(order[i] + 1, 1, 0, n - 1);
		update(k, 0, 1, 0, n - 1);
		res[i] = arr[k];
	}
	for (int i = 0; i < n; i++)
		printf("%d\n", res[i]);

	return 0;
}