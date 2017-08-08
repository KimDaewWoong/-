#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int n, in[510], dtime[510], res[510];
vector<vector<int>> vt;
priority_queue<int> pq;
int main() {
	scanf("%d", &n);
	vt.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &dtime[i]);
		int pre;
		while (scanf("%d", &pre) != -1 && pre != -1) {
			vt[pre].push_back(i);
			in[i]++;
		}
	}
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

	for (int i = 1; i <= n; i++) printf("%d\n", res[i]);

	return 0;
}