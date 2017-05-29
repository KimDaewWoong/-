#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll n, a, b, bmatch[10010], result[10010];
bool visited[10010];
vector<vector<ll>> vt;
pair<ll, ll> pa[10010];
int dfs(ll here) {
	if (visited[here]) return 0;
	visited[here] = true;
	for (int i = 0; i < vt[here].size(); i++) {
		ll there = vt[here][i];
		if (!bmatch[there] || dfs(bmatch[there])) {
			result[here] = there;
			bmatch[there] = here;
			return 1;
		}
	}
	return 0;
}
int func() {
	int res = 0;
	for (int i = 1; i <= n; i++) {
		memset(visited, false, sizeof(visited));
		if (dfs(i)) res++;
	}
	return res;
}
int main() {
	freopen("input.txt", "r", stdin);
	vector<ll> pos;
	scanf("%lld", &n);
	vt.resize(3 * (n + 1));
	for (int i = 1; i <= n; i++) {
		scanf("%lld %lld", &a, &b);
		pa[i].first = a;
		pa[i].second = b;
		pos.push_back(a + b);
		pos.push_back(a - b);
		pos.push_back(a * b);
	}
	sort(pos.begin(), pos.end());
	pos.erase(unique(pos.begin(), pos.end()), pos.end());

	for (int i = 1; i <= n; i++) {
		int x = lower_bound(pos.begin(), pos.end(), pa[i].first + pa[i].second) - pos.begin();
		int y = lower_bound(pos.begin(), pos.end(), pa[i].first - pa[i].second) - pos.begin();
		int z = lower_bound(pos.begin(), pos.end(), pa[i].first * pa[i].second) - pos.begin();
		vt[i].push_back(x);
		vt[i].push_back(y);
		vt[i].push_back(z);
	}

	int res = func();
	if (res != n) {
		puts("impossible");
		return 0;
	}

	for (int i = 1; i <= n; i++) {
		int q = result[i];
		if (pos[q] == pa[i].first + pa[i].second)
			printf("%lld + %lld = %lld\n", pa[i].first, pa[i].second, pa[i].first + pa[i].second);
		else if (pos[q] == pa[i].first - pa[i].second)
			printf("%lld - %lld = %lld\n", pa[i].first, pa[i].second, pa[i].first - pa[i].second);
		else
			printf("%lld * %lld = %lld\n", pa[i].first, pa[i].second, pa[i].first * pa[i].second);
	}

	return 0;
}