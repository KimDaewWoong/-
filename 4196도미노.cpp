#include<cstdio>
#include<algorithm>
#include<cstring>
#include<stack>
#include<vector>
using namespace std;
int t, n, m, cnt, SN;
int in[100100], sn[100100], dfsn[100100];
bool finish[100100];
vector<vector<int>> vt, scc;
vector<int> fr;
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
			fr.push_back(t);
			finish[t] = true;
			sn[t] = SN;
			if (t == pos) break;
		}
		scc.push_back(fr);
		fr.clear();
		SN++;
	}
	return res;
}
int main() {
	scanf("%d", &t);
	while (t--) {
		vt.clear();
		scc.clear();
		memset(in, 0, sizeof(in));
		memset(sn, 0, sizeof(sn));
		memset(dfsn, -1, sizeof(dfsn));
		memset(finish, false, sizeof(finish));

		scanf("%d %d", &n, &m);
		vt.resize(n + 1);
		for (int i = 0; i < m; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			vt[a].push_back(b);
		}
		cnt = 0; SN = 0;
		for (int i = 1; i <= n; i++)
			if (dfsn[i] == -1)
				dfs(i);

		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < vt[i].size(); j++) {
				int there = vt[i][j];
				if (sn[i] != sn[there]) in[sn[there]]++;
			}
		}
		int ans = 0;
		for (int i = 0; i < SN; i++) {
			if (!in[i]) ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}