#include<cstdio>
#include<vector>
#include<algorithm>
typedef long long ll;
using namespace std;
ll n, m, test, limit, t, ans;
vector<ll> vi, vii, sa, sb;
void ssum(ll length, ll sum, vector<ll> &vi, vector<ll> &sa) {
	if (length == vi.size()) {
		sa.push_back(sum);
		return;
	}
	//두번째 값을 증가시키면서 더하고
	ssum(length + 1, vi[length] + sum, vi, sa);
	//첫번째 값을 증가시키면서 더하고
	ssum(length + 1, sum, vi, sa);
}
int main() {
	ll temp;
	scanf("%lld %lld", &n, &m);
	for (ll i = 0; i < n / 2; i++) {
		scanf("%lld", &temp);
		vi.push_back(temp);
	}
	ssum(0, 0, vi, sa);

	for (ll i = 0; i < n - n / 2; i++) {
		scanf("%lld", &temp);
		vii.push_back(temp);
	}
	ssum(0, 0, vii, sb);

	sort(sb.begin(), sb.end());
	long long litor, uitor;
	for (ll i = 0; i < sa.size(); i++) {
		litor = lower_bound(sb.begin(), sb.end(), m - sa[i]) - sb.begin();
		uitor = upper_bound(sb.begin(), sb.end(), m - sa[i]) - sb.begin();
		ans += (uitor - litor);
	}
	if (m == 0) printf("%lld\n", ans - 1);
	else printf("%lld\n", ans);
}
