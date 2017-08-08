#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int n, m, indegree[32100];
vector<vector<int>> vt;
priority_queue<int> pq;
int main() {
	scanf("%d %d", &n, &m);
	vt.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		vt[a].push_back(b);
		indegree[b]++;
	}
	for (int i = 1; i <= n; i++)
		if (!indegree[i]) pq.push(-i);

	while (pq.size()) {
		int here = -pq.top();
		pq.pop();
		printf("%d ", here);
		for (int i = 0; i < vt[here].size(); i++) {
			int there = vt[here][i];
			indegree[there]--;
			if (!indegree[there]) pq.push(-there);
		}
	}

	return 0;
}