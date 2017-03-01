#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int n, m;
vector<int> seg[400040];
int query(int lo, int hi, int node, int val, int left, int right) {
	if (hi < left || right < lo) return 0;
	if (lo <= left && right <= hi) 	return upper_bound(seg[node].begin(), seg[node].end(), val) - seg[node].begin();
	int mid = (left + right) >> 1;
	int lcv = query(lo, hi, node * 2, val, left, mid);
	int rcv = query(lo, hi, node * 2 + 1, val, mid + 1, right);
	return lcv + rcv;
}
int main() {
	scanf("%d%d", &n, &m);
	int idx = 1;
	while (idx < n) idx <<= 1;
	for (int i = 0; i < n; i++) {
		int val;
		scanf("%d", &val);
		seg[idx + i] = vector<int>(1, val);
	}
	for (int i = idx; i > 0; i /= 2) {
		for (int j = i; j < i * 2; j += 2) {
			vector<int> a = seg[j];
			vector<int> b = seg[j + 1];
			vector<int> c;
			c.resize(a.size() + b.size());
			merge(a.begin(), a.end(), b.begin(), b.end(), c.begin());
			seg[j / 2] = c;
		}
	}
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		int lo = -1000000000, hi = 1000000000;
		while (lo < hi) {
			int mid = (lo + hi) >> 1;
			if (query(a, b, 1, mid, 1, idx) < c) {
				lo = mid + 1;
			}
			else hi = mid;
		}
		printf("%d\n", lo);
	}
	return 0;
}