#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
#include<cstring>
using namespace std;
int n;
bool visit[220];
vector<vector<int>> vt;
pair<pair<int, int>, long long> pa[220];
int dfs(int pos) {
	int cnt = 1;
	visit[pos] = true;
	for (int i = 0; i < vt[pos].size(); i++) {
		if (!visit[vt[pos][i]]) {
			cnt += dfs(vt[pos][i]);
		}
	}
	return cnt;
}
int main() {
	scanf("%d", &n);
	vt.resize(n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %lld", &pa[i].first.first, &pa[i].first.second, &pa[i].second);
		pa[i].second *= pa[i].second;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			if (pa[i].second >= ((pa[j].first.first - pa[i].first.first) * (pa[j].first.first - pa[i].first.first)) +
				((pa[j].first.second - pa[i].first.second) * (pa[j].first.second - pa[i].first.second))) {
				vt[i].push_back(j);
			}
		}
	}
	int res = 0;

	for (int i = 0; i < n; i++) {
		memset(visit, false, sizeof(visit));
		for (int j = 0; j < n; j++) {
			if (!visit[i]) {
				res = max(res, dfs(i));
			}
		}
	}

	printf("%d", res);

	return 0;
}