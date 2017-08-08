#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
int t, k, n, m;
int in[1010];
pair<int, int> st[1010];
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &t);
	while (t--) {
		vector<vector<int>> vt;
		memset(in, 0, sizeof(in));
		memset(st, 0, sizeof(st));
		scanf("%d %d %d", &k, &n, &m);
		vt.resize(n + 1);
		for (int i = 0; i < m; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			vt[a].push_back(b);
			in[b]++;
		}
		priority_queue<int> pq;
		for (int i = 1; i <= n; i++) {
			if (!in[i]) {
				pq.push(-i);
				st[i].first = 1;
			}
		}

		while (pq.size()) {
			int here = -pq.top();
			pq.pop();
			for (int i = 0; i < vt[here].size(); i++) {
				int there = vt[here][i];
				if (st[there].first < st[here].first) {
					st[there].first = st[here].first;
					st[there].second = 1;
				}
				else if (st[there].first == st[here].first) {
					if (st[there].second == 1) {
						st[there].first++;
						st[there].second++;
					}
				}
				in[there]--;
				if (!in[there]) {
					pq.push(-there);
				}
			}
		}
		sort(st, st + n);
		printf("%d %d\n", k, st[n].first);
	}
	return 0;
}