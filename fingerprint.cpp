#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
int t, n, m;
pair<int, int> pa[100];
pair<int, int> cm[100];
int main() {
	scanf("%d", &t);
	while (t--) {
		set<pair<int, int>> a;
		memset(pa, 0, sizeof(pa));
		memset(cm, 0, sizeof(cm));
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			int x, y;
			scanf("%d %d", &x, &y);
			pa[i].first = x;
			pa[i].second = y;
		}

		scanf("%d", &m);
		for (int i = 0; i < m; i++) {
			int x, y;
			scanf("%d %d", &x, &y);
			cm[i].first = x;
			cm[i].second = y;
			a.insert({ x, y });
		}
		sort(pa, pa + n);
		sort(cm, cm + m);
		int maxx = -1;
		bool flag = false;
		for (int i = 0; i < n*0.1; i++) {
			for (int j = 0; j < m*0.1; j++) {
				int cnt = 0;
				int xgap = pa[i].first - cm[j].first;
				int ygap = pa[i].second - cm[j].second;
				for (int k = 0; k < n; k++)
					if (a.count({ pa[k].first - xgap, pa[k].second - ygap }))
						cnt++;

				maxx = max(cnt, maxx);
				if ((100 * maxx / n) >= 90) {
					flag = true;
					break;
				}
			}
			if (flag) break;
		}
		if (flag) puts("1");
		else puts("0");
	}
	return 0;
}