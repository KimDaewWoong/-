#include<cstdio>
#include<vector>
#include<stack>
#include<cstring>
#include<algorithm>
using namespace std;
int v, e, a;
bool visited[10010];
vector<vector<int>> vt, re, scc;
stack<int> st;

void dfs(int pos) {
	visited[pos] = true;
	for (auto there : vt[pos]) {
		if (!visited[there]) {
			dfs(there);
		}
	}
	st.push(pos);
}
void rev(int pos, int n) {
	visited[pos] = true;
	scc[n].push_back(pos);
	for (auto there : re[pos]) {
		if (!visited[there]) {
			rev(there, n);
		}
	}
}
int main() {
	scanf("%d%d", &v, &e);
	vt.resize(v + 1);
	re.resize(v + 1);
	for (int i = 0; i < e; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		vt[a].push_back(b);
		re[b].push_back(a);
	}
	for (int i = 1; i <= v; i++) {
		if (!visited[i]) dfs(i);
	}
	memset(visited, false, sizeof(visited));
	while (st.size()) {
		int pos = st.top();
		st.pop();
		if (!visited[pos]) {
			a++;
			scc.resize(a);
			rev(pos, a - 1);
		}
	}
	for (int i = 0; i < a; i++)
		sort(scc[i].begin(), scc[i].end());

	sort(scc.begin(), scc.end());
	printf("%d\n", a);
	for (int i = 0; i < a; i++) {
		for (int x : scc[i])
			printf("%d ", x);
		puts("-1");
	}
	return	0;
}