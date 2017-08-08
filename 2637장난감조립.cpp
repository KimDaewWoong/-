#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
int n, m, cnt;
int in[111], arr[111][111], r[111];
vector<vector<int>> vt;
priority_queue<int> pq;
int main() {
	scanf("%d %d", &n, &m);
	vt.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b, w;
		scanf("%d %d %d", &a, &b, &w);
		vt[b].push_back(a);
		in[a]++;
		arr[a][b] = w;
	}
	for (int i = 1; i <= n; i++)
		if (!in[i]) {
			pq.push(-i);
			arr[i][i] = 1;
			r[i] = 1;
		}
	while (pq.size()) {
		int here = -pq.top();
		pq.pop();
		for (int i = 0; i < vt[here].size(); i++) {
			int there = vt[here][i];
			for (int i = 1; i <= n; i++)
				if (i != here)
					arr[there][i] += (arr[there][here] * arr[here][i]);
			in[there]--;
			if (!in[there]) {
				pq.push(-there);
			}
		}
	}
	for (int i = 1; i <= n; i++)
		if (r[i]) printf("%d %d\n", i, arr[n][i]);

	return 0;
}