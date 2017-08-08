#include<cstdio>
#include<algorithm>
#include<stack>
#include<vector>
#include<cstring>
using namespace std;
int t, n, m, cnt, SN, in[100100], dfsn[100100], sn[100100];
bool finish[100100];
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
	scanf("%d", &t);
	while (t--) {
		memset(dfsn, -1, sizeof(dfsn));
		memset(sn, 0, sizeof(sn));
		memset(in, 0, sizeof(in));
		memset(finish, false, sizeof(finish));
		scanf("%d %d", &n, &m);
		vt.resize(n);
		for (int i = 0; i < m; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			vt[a].push_back(b);
		}
		getchar();
		cnt = 0, SN = 0;
		for (int i = 0; i < n; i++)
			if (dfsn[i] == -1)
				dfs(i);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < vt[i].size(); j++) {
				int there = vt[i][j];
				if (sn[i] != sn[there]) in[sn[there]]++;
			}
		}
		vector<int> res;
		int d = 0;
		for (int i = 0; i < SN; i++) {
			if (!in[i]) {
				for (int j = 0; j < scc[i].size(); j++) {
					res.push_back(scc[i][j]);
				}
				d++;
			}
		}

		sort(res.begin(), res.end());

		if (d >= 2) puts("Confused");
		else if (d == 1)
			for (int i = 0; i < res.size(); i++)
				printf("%d\n", res[i]);
		puts("");

		res.clear();
		vt.clear();
		scc.clear();
	}
	return 0;
}