#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
int t, n, m;
long long S[1010], A[1010];
vector <long long> vt;
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		vt.resize(n + 1);
		int a, b, p, q;
		for (int i = 1; i <= m; i++) {
			scanf("%d%d%d%d", &a, &b, &p, &q);
			S[a] += p; A[b] += p;
			S[b] += q; A[a] += q;
		}
		for (int i = 1; i <= n; i++) {
			if (!S[i] && !A[i]) vt[i] = 0;
			else vt[i] = (S[i] * S[i]) * 1000 / ((S[i] * S[i]) + (A[i] * A[i]));
		}
		sort(vt.begin(), vt.end());

		printf("%lld\n%lld\n", vt[n], vt[1]);
		vt.clear();
		memset(S, 0, sizeof(S));
		memset(A, 0, sizeof(A));
	}
	return 0;
}