#include<cstdio>
#include<algorithm>
#include<vector>
#include<stack>
#include<cstring>
using namespace std;
int n, m, in[5050], dfsn[5050], sn[5050], SN, cnt;
bool finish[5050];
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
			finish[t] = true;
			sn[t] = SN;
			temp.push_back(t);
			if (t == pos) break;
		}
		scc.push_back(temp);
		temp.clear();
		SN++;
	}
	return res;
}
int main() {
	while (scanf("%d", &n) != EOF && n) {
		memset(finish, false, sizeof(finish));
		memset(in, 0, sizeof(in));
		memset(dfsn, -1, sizeof(dfsn));
		memset(sn, 0, sizeof(sn));
		vt.resize(n + 1);
		scanf("%d", &m);
		for (int i = 0; i < m; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			vt[a].push_back(b);
		}
		cnt = 0; SN = 0;

		for (int i = 1; i <= n; i++)
			if (dfsn[i] == -1) dfs(i);

		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < vt[i].size(); j++) {
				int there = vt[i][j];
				if (sn[i] != sn[there]) in[sn[i]]++;
			}
		}
		vector<int> res;
		for (int i = 0; i < SN; i++)
			if (!in[i])
				for (int j = 0; j < scc[i].size(); j++)
					res.push_back(scc[i][j]);

		sort(res.begin(), res.end());

		for (int i = 0; i < res.size(); i++) printf("%d ", res[i]);

		puts("");
		scc.clear();
		vt.clear();
	}
	return 0;
}