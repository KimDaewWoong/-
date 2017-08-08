#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int t, n, m, L, hp, k;
int A[1050], B[1050];
pair<int, int> pa[6250010];
int main() {
	scanf("%d", &t);
	while (t--) {
		memset(pa, 0, sizeof(pa));
		pair<int, int> knight[2];
		scanf("%d %d", &m, &n);
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				int mul;
				scanf("%d", &mul);
				pa[mul].first = i;
				pa[mul].second = j;
			}
		}

		scanf("%d", &k);
		while (k--) {
			memset(A, 0, sizeof(A));
			memset(B, 0, sizeof(B));
			scanf("%d", &L);
			for (int i = 0; i < L; i++) scanf("%d", &A[i]);
			for (int i = 0; i < L; i++) scanf("%d", &B[i]);
			int x, y, ahp, bhp, apos, bpos;
			scanf("%d %d %d", &hp, &x, &y);
			ahp = bhp = hp;
			knight[0].first = knight[1].first = x;
			knight[0].second = knight[1].second = y;
			int turn = apos = bpos = 0;
			while (ahp > 0 && bhp > 0) {
				if (!turn) {
					int sub = abs(pa[A[apos] * (A[(apos + 1) % L])].first - knight[1].first) + abs(pa[A[apos] * (A[(apos + 1) % L])].second - knight[1].second);

					knight[1].first = pa[A[apos] * (A[(apos + 1) % L])].first;
					knight[1].second = pa[A[apos] * (A[(apos + 1) % L])].second;
					apos = (apos + 2) % L;
					bhp -= sub;
					turn = 1;
				}
				else {
					int sub = abs(pa[B[bpos] * (B[(bpos + 1) % L])].first - knight[0].first) + abs(pa[B[bpos] * (B[(bpos + 1) % L])].second - knight[0].second);

					knight[0].first = pa[B[bpos] * (B[(bpos + 1) % L])].first;
					knight[0].second = pa[B[bpos] * (B[(bpos + 1) % L])].second;
					bpos = (bpos + 2) % L;
					ahp -= sub;
					turn = 0;
				}
			}
			if (ahp <= 0) puts("B");
			else puts("A");
		}
	}
	return 0;
}