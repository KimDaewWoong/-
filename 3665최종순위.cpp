#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
int t, n, m;
int in[555], ti[555];
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &t);
	while (t--) {
		memset(in, 0, sizeof(in));
		memset(ti, 0, sizeof(ti));
		scanf("%d", &n);
		vector<vector<int>> vt(n + 1, vector<int>(n + 1, 0));
		for (int i = 0; i < n; i++)	scanf("%d", &ti[i]);

		scanf("%d", &m);
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				vt[ti[i]][ti[j]] = 1;
				in[ti[j]]++;
			}
		}
		for (int i = 0; i < m; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			if (vt[a][b]) {
				in[a]++; in[b]--;
			}
			else {
				in[b]++; in[a]--;
			}
			swap(vt[a][b], vt[b][a]);
		}
		priority_queue<int> pq;
		for (int i = 1; i <= n; i++)
			if (!in[i])	pq.push(-i);

		vector<int> res;
		int d = 0;
		for (int i = 1; i <= n; i++) {
			if (pq.empty()) {
				d = 1;
				break;
			}
			if (pq.size() >= 2) {
				d = 2;
				break;
			}
			int here = -pq.top();
			pq.pop();
			res.push_back(here);
			for (int j = 1; j <= n; j++) {
				if (!vt[here][j]) continue;
				in[j]--;
				if (!in[j]) pq.push(-j);
			}
		}
		if (d == 1)
			puts("IMPOSSIBLE");
		else if (d == 2)
			puts("?");
		else {
			for (int i = 0; i < res.size(); i++) printf("%d ", res[i]);
			puts("");
		}
		vt.clear();
		res.clear();
	}
	return 0;
}