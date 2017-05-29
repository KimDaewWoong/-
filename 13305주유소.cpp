#include<cstdio>
#include<algorithm>
#include<vector>
#define INF 1000000001
typedef long long ll;
using namespace std;
int n;
vector<ll> vt, we;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		ll a;
		scanf("%lld", &a);
		vt.push_back(a);
	}
	for (int i = 0; i < n; i++) {
		ll a;
		scanf("%lld", &a);
		we.push_back(a);
	}
	ll ans = 0;
	ll oil = INF;
	for (int i = 0; i<we.size() - 1; i++) {
		oil = min(oil, we[i]);
		ans += oil*vt[i];
	}
	printf("%lld\n", ans);

	return 0;
}