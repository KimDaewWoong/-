#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
int t, N, d, arr[20];
ll fact(ll n, ll r) {
	ll f = 1;
	if (!n) return 1;
	for (int i = 0; i < r; i++) f *= (n - i);
	return f;
}
ll nhr(ll n, ll r) {
	n += r - 1;
	return fact(n, r) / fact(r, r);
}
ll func(ll a, ll b) {
	ll ret = 0;
	if (b == 0) return 1;
	for (int i = 1; i <= b; i++)
		ret += func(i, b - i) * nhr(a, i);
	return ret;
}
int main() {
	//freopen("input.txt", "r", stdin);
	scanf("%d", &t);
	while (t--) {
		memset(arr, 0, sizeof(arr));
		scanf("%d %d", &N, &d);
		ll node = 0;
		for (int i = 0; i <= d; i++) {
			scanf("%d", &arr[i]);
			node += arr[i];
		}
		ll res = 1ll;
		for (int i = 0; i < d; i++)
			res *= nhr(arr[i], arr[i + 1]);
		res *= func(arr[d], N - node);
		printf("%lld\n", res);
	}
	return 0;
}