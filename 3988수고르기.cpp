#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;
int n, k, arr[1010000];
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &n, &k);
	int m = 0, M = 0;
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	sort(arr, arr + n);
	k = n - k;
	multiset<int> st;
	multiset<int>::iterator it;
	int res = 2e9;
	for (int i = 0; i < n - 1; i++) {
		int L = i - k + 1;
		int R = i + k - 1;
		m = arr[i + 1] - arr[i];
		if (R < n) {
			st.insert(arr[R] - arr[i]);
		}
		if (L >= 0) {
			st.erase(st.find(arr[i] - arr[L]));
		}
		it = st.begin();
		M = *it;
		res = min(res, m + M);
	}
	printf("%d", res);
	return 0;
}