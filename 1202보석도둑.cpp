#include<cstdio>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;
multiset<int> st;
int n, k, a;
long long sum;
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &n, &k);
	vector<pair<int, int>> pr(n);
	for (int i = 0; i < n; i++)	scanf("%d %d", &pr[i].second, &pr[i].first);
	for (int i = 0; i < k; i++) {
		scanf("%d", &a);
		st.insert(a);
	}
	sort(pr.begin(), pr.end());
	reverse(pr.begin(), pr.end());
	
	for (int i = 0; i < n; i++) {
		multiset<int>::iterator it = st.lower_bound(pr[i].second);
		if (it != st.end()) {
			sum += pr[i].first;
			st.erase(it);
		}
	}
	printf("%lld\n", sum);
	return 0;
}