#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
int t, n, x, y, seg[400040], bank[100010];
pair <int, int> a[100010];
bool cmp(pair<int, int> x, pair<int, int> y) {
	if (x.first == y.first)
		return x.second > y.second;
	return x.first < y.first;
}
int update(int pos, int val, int node, int x, int y) {
	if (y < pos || pos < x) return seg[node];
	if (x == y) return seg[node] = val;
	int mid = (x + y) >> 1;
	return seg[node] = update(pos, val, node * 2, x, mid) + update(pos, val, node * 2 + 1, mid + 1, y);
}
int query(int lo, int hi, int node, int x, int y) {
	if (y < lo || x > hi) return 0;
	if (lo <= x && hi >= y) return seg[node];
	int mid = (x + y) >> 1;
	return query(lo, hi, node * 2, x, mid) + query(lo, hi, node * 2 + 1, mid + 1, y);
}
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &t);
	while (t--) {
		memset(seg, 0, sizeof(seg));
		memset(bank, 0, sizeof(bank));
		scanf("%d", &n);
		vector<int> ypos;
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &x, &y);
			a[i] = { x, y };
			ypos.push_back(y);
		}
		sort(a, a + n, cmp);
		sort(ypos.begin(), ypos.end());
		long long res = 0;
		for (int i = 0; i < n; i++) {
			int z = lower_bound(ypos.begin(), ypos.end(), a[i].second) - ypos.begin();
			res += (long long)query(z, ypos.size() - 1, 1, 0, ypos.size() - 1);
			bank[z]++;
			update(z, bank[z], 1, 0, ypos.size() -1);
		}
		printf("%lld\n", res);
	}
	return 0;
}