#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
int t, n, m, w, in[1010], dtime[1010], res[1010];
int main() {
	scanf("%d", &t);
	while (t--) {
		memset(in, 0, sizeof(in));
		memset(dtime, 0, sizeof(dtime));
		memset(res, 0, sizeof(res));

		scanf("%d %d", &n, &m);

		vector<vector<int>> vt;
		vt.resize(n + 1);
		for (int i = 1; i <= n; i++)
			scanf("%d", &dtime[i]);
		for (int i = 0; i < m; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			vt[a].push_back(b);
			in[b]++;
		}
		priority_queue<int> pq;
		for (int i = 1; i <= n; i++)
			if (!in[i]) {
				pq.push(-i);
				res[i] = dtime[i];
			}

		while (pq.size()) {
			int here = -pq.top();
			pq.pop();
			for (int i = 0; i < vt[here].size(); i++) {
				int there = vt[here][i];
				res[there] = max(res[there], res[here] + dtime[there]);
				in[there]--;
				if (!in[there]) pq.push(-there);
			}
		}
		scanf("%d", &w);
		printf("%d\n", res[w]);
	}
	return 0;
}