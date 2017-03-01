#include<cstdio>
#include<algorithm>
typedef long long ll;
using namespace std;
int n;
ll arr[100010], seg[400040];

ll update(int pos, ll val, int node, int left, int right) {
	if (pos < left || right < pos) return seg[node];
	if (left == right) return seg[node]=val;
	int mid = (left + right) >> 1;
	ll lcv = update(pos, val, node * 2, left, mid);
	ll rcv = update(pos, val, node * 2 + 1, mid + 1, right);
	return seg[node] = lcv + rcv;
}
ll sum(int lo, int hi, int node, int left, int right) {
	if (hi < left || right < lo) return 0;
	if (lo <= left && right <= hi) return seg[node];
	int mid = (left + right) >> 1;
	ll lcv = sum(lo, hi, node * 2, left, mid);
	ll rcv = sum(lo, hi, node * 2 + 1, mid + 1, right);
	return lcv + rcv;
}
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		ll val;
		scanf("%lld", &val);
		arr[val] = i;
		update(i, 1, 1, 0, n - 1);
	}
	for (int i = 1; i <= n; i++) {
		int j;
		if (i&1) {
			j = (i / 2)+1;
			printf("%lld\n", sum(0, arr[j]-1, 1, 0, n - 1));
		}
		else { 
			j = n - (i / 2)+1;
			printf("%lld\n", sum(arr[j]+1, n-1, 1, 0, n - 1)); 
		}
		update(arr[j], 0, 1, 0, n - 1);
	}
	return 0;
}