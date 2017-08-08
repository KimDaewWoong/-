#include<cstdio>
#include<algorithm>
#include<stack>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;
int n, m, s, t, cnt, SN, in[10010], dfsn[10010], sn[10010], sdist[10010], res[10010];
bool finish[10010], scal[10010];
vector<vector<int>> vt, scc;
vector<int> temp;
stack<int> st;
int dfs(int pos) {
	dfsn[pos] = ++cnt;
	st.push(pos);
	int res = dfsn[pos];
	for (int i = 0; i < vt[pos].size(); i++) {
		int next = vt[pos][i];
		if (dfsn[next] == -1) res = min(res, dfs(next));
		else if (!finish[next]) res = min(res, dfsn[next]);
	}
	if (res == dfsn[pos]) {
		while (1) {
			int t = st.top();
			st.pop();
			temp.push_back(t);
			finish[t] = true;
			sn[t] = SN;
			if (t == pos) break;
		}
		SN++;
		scc.push_back(temp);
		temp.clear();
	}
	return res;
}
int main() {
	memset(dfsn, -1, sizeof(dfsn));
	scanf("%d %d %d %d", &n, &m, &s, &t);
	vt.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		vt[a].push_back(b);
	}
	cnt = 0, SN = 0;
	for (int i = 1; i <= n; i++)
		if (dfsn[i] == -1)
			dfs(i);

	for (int i = 0; i < SN; i++) sdist[i] = scc[i].size();
	vector<vector<int>> svt;
	svt.resize(SN + 1);
	int ss = sn[s], st = sn[t];

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < vt[i].size(); j++) {
			int there = vt[i][j];
			if (sn[i] != sn[there]) {
				svt[sn[i]].push_back(sn[there]);
				in[sn[there]]++;
			}
		}
	}

	scal[ss] = true;
	queue<int> qu;
	for (int i = 0; i < SN; i++) {
		res[i] = sdist[i];
		if (!in[i]) qu.push(i);
	}

	while (!qu.empty()) {
		int here = qu.front();
		qu.pop();
		for (int i = 0; i < svt[here].size(); i++) {
			int there = svt[here][i];
			if (scal[here]) {
				res[there] = max(res[there], res[here] + sdist[there]);
				scal[there] = true;
			}
			in[there]--;
			if (!in[there]) qu.push(there);
		}
	}
	if (scal[st]) printf("%d\n", res[st]);
	else puts("0");

	return 0;
}