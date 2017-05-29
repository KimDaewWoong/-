#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
int p[200010], arr[200010], n, q;
pair<int, int> pa[400010];
stack<int> st;
int find(int n) {
	if (n == p[n]) return n;
	return p[n] = find(p[n]);
}
void merge(int a, int b) {
	a = find(a); b = find(b);
	if (a == b) return;
	if (a > b) swap(a, b);
	p[a] = b;
}
int main() {
	scanf("%d %d", &n, &q);
	for (int i = 2; i <= n; i++) {
		int a;
		scanf("%d", &a);
		arr[i] = a;
		p[i] = i;
	}
	for (int i = 0; i < n - 1 + q; i++) {
		int x;
		scanf("%d", &x);
		if (x) {
			int c, d;
			scanf("%d %d", &c, &d);
			pa[i].first = c;
			pa[i].second = d;
		}
		else {
			int b;
			scanf("%d", &b);
			pa[i].second = b;
		}
	}
	reverse(pa, pa + n - 1 + q);
	for (int i = 0; i < n - 1 + q; i++) {
		if (!pa[i].first) merge(pa[i].second, arr[pa[i].second]);
		else {
			if (find(pa[i].first) == find(pa[i].second)) {
				st.push(1);
			}
			else {
				st.push(0);
			}
		}
	}
	while (!st.empty()) {
		if (st.top())
			puts("YES");
		else
			puts("NO");
		st.pop();
	}
	return 0;
}