#include<cstdio>
#include<vector>
#include<algorithm>
typedef long long ll;
using namespace std;
pair<ll, ll> q[100100];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%lld %lld", &q[i].second, &q[i].first);
	sort(q, q + n);
	ll res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = n - 1; j >= 0; j--) {
			if (!q[i].second) break;
			if (!q[j].second) continue;
			res = max(res, q[i].first + q[j].first);
			if (q[i].second > q[j].second) {
				q[i].second -= q[j].second;
				q[j].second = 0;
			}
			else if (q[i].second < q[j].second) {
				q[j].second -= q[i].second;
				q[i].second = 0;
			}
			else
				q[i].second = q[j].second = 0;
		}
	}
	printf("%lld", res);
	return 0;
}