#include<cstdio>
#include<vector>
#include<stack>
using namespace std;
int n, m;
bool visit[32010];
vector<vector<int>> vt;
stack <int> st;
void dfs(int pos) {
	visit[pos] = true;
	for (auto there : vt[pos]) {
		if (!visit[there]) {
			dfs(there);
		}
	}
	st.push(pos);
}
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d%d", &n, &m);
	vt.resize(n+1);
	int a, b;
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &a, &b);
		vt[a].push_back(b);
	}
	for (int i = 1; i <= n; i++) {
		if (!visit[i])
			dfs(i);
	}
	while (st.size()) {
		printf("%d ", st.top());
		st.pop();
	}
	return 0;
}