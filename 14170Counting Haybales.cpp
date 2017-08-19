#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>
#include<cstring>
typedef long long ll;
using namespace std;
ll arr[100100];
int main() {
	freopen("input.txt", "r", stdin);
	ll n, q;
	scanf("%lld %lld", &n, &q);
	for (int i = 0; i < n; i++)
		scanf("%lld", &arr[i]);
	sort(arr, arr + n);

	for (int i = 0; i < q; i++) {
		ll a, b;
		scanf("%lld %lld", &a, &b);
		if (a > b) swap(a, b);
		a = lower_bound(arr, arr + n, a) - arr;
		b = upper_bound(arr, arr + n, b) - arr;
		printf("%lld\n", b - a);
	}
	return 0;
}