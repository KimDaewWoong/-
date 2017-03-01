#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int n;
int q[4500], w[4500], e[4500], r[4500];
long long cnt;
vector<int> a;
vector<int> b;
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d %d", &q[i], &w[i], &e[i], &r[i]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a.push_back(q[i] + w[j]);
			b.push_back(e[i] + r[j]);
		}
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	int lopos, uppos;
	for (int i = 0; i < a.size(); i++) {
		lopos = lower_bound(b.begin(), b.end(), -a[i]) - b.begin();
		uppos = upper_bound(b.begin(), b.end(), -a[i]) - b.begin();
		cnt += (uppos - lopos);
	}
	printf("%lld", cnt);
	return 0;
}