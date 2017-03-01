#include<cstdio>
#include<algorithm>
using namespace std;
int n, cnt, seg[2000020];
int INF = 987654321;
pair <int, pair<int, int>> pr[500050];
int update(int pos, int val, int node, int left, int right) {
	if (pos<left || pos>right) return seg[node];
	if (left == right) return seg[node] = val;
	int mid = (left + right) >> 1;
	int lcv = update(pos, val, node * 2, left, mid);
	int rcv = update(pos, val, node * 2 + 1, mid + 1, right);
	return seg[node] = min(lcv, rcv);
}
int minn(int lo, int hi, int node, int left, int right) {
	if (left > hi || right < lo) return INF;
	if (hi >= right && lo <= left) return seg[node];
	int mid = (left + right) >> 1;
	int lcv = minn(lo, hi, node * 2, left, mid);
	int rcv = minn(lo, hi, node * 2 + 1, mid + 1, right);
	return min(lcv, rcv);
}
int main() {
	scanf("%d", &n);
	int val;
	for (int i = 0; i < n; i++) {
		scanf("%d", &val);
		pr[val - 1].first = i;
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &val);
		pr[val - 1].second.first = i;
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &val);
		pr[val - 1].second.second = i;
	}
	sort(pr, pr + n);
	for (int i = 0; i < n; i++) update(i, INF, 1, 0, n - 1);
	for (int i = 0; i < n; i++) {
		if (pr[i].second.second < minn(0, pr[i].second.first-1, 1, 0, n - 1)) cnt++;

		update(pr[i].second.first, pr[i].second.second, 1, 0, n - 1);
	}
	printf("%d", cnt);
	return 0;
}