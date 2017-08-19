#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int MAX = 25000;
int n, seg[MAX * 4];
pair<int, int> pa[MAX];
vector<int> ypos;
int update(int pos, int val, int node, int l, int r) {
	if (pos < l || pos > r) return seg[node];
	if (l == r) return seg[node] += val;
	int mid = (l + r) >> 1;
	return seg[node] = update(pos, val, node * 2, l, mid) + update(pos, val, node * 2 + 1, mid + 1, r);
}
int query(int lo, int hi, int node, int l, int r) {
	if (lo > r || hi < l) return 0;
	if (lo <= l && hi >= r) return seg[node];
	int mid = (l + r) >> 1;
	return query(lo, hi, node * 2, l, mid) + query(lo, hi, node * 2 + 1, mid + 1, r);
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &pa[i].second, &pa[i].first);
		ypos.push_back(pa[i].second);
	}
	sort(pa, pa + n);
	sort(ypos.begin(), ypos.end());
	ypos.erase(unique(ypos.begin(), ypos.end()), ypos.end());
	int res = 0;
	for (int i = 0; i < n; i++) {
		int idx = lower_bound(ypos.begin(), ypos.end(), pa[i].second) - ypos.begin();
		res = max(res, query(idx, n - 1, 1, 0, n - 1));
		update(idx, 1, 1, 0, n - 1);
	}

	printf("%d\n", res);

	return 0;
}