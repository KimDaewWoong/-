//위상정렬
//indegree
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int n, m, indegree[1100];
vector<vector<int>> vt;
priority_queue<int> pq;
int main() {
	scanf("%d %d", &n, &m);
	vt.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int a, cur, next;
		scanf("%d %d", &a, &cur);
		for (int j = 1; j < a; j++) {
			scanf("%d", &next);
			vt[cur].push_back(next);
			indegree[next]++;
			cur = next;
		}
	}
	for (int i = 1; i <= n; i++)
		if (!indegree[i]) pq.push(-i);

	vector<int> res;
	while (pq.size()) {
		int here = -pq.top();
		pq.pop();
		res.push_back(here);
		for (int i = 0; i < vt[here].size(); i++) {
			int there = vt[here][i];
			indegree[there]--;
			if (!indegree[there]) pq.push(-there);
		}
	}
	if (res.size() != n) {
		puts("0");
		return 0;
	}

	for (int i = 0; i < res.size(); i++) printf("%d\n", res[i]);
	return 0;
}

//-------------------------------------------------------------------
//dfs
#include<cstdio>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;
int n, m;
bool visit[1100], finish[1100], flag;
vector<vector<int>> vt;
stack<int> st;
void dfs(int pos) {
	visit[pos] = true;
	for (int i = 0; i < vt[pos].size(); i++) {
		int next = vt[pos][i];
		if (visit[next]) {
			if (!finish[next]) {
				flag = true;
				return;
			}
		}
		else dfs(next);
	}
	finish[pos] = true;
	st.push(pos);
}
int main() {
	scanf("%d %d", &n, &m);
	vt.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int a, cur, next;
		scanf("%d %d", &a, &cur);
		for (int j = 1; j < a; j++) {
			scanf("%d", &next);
			vt[cur].push_back(next);
			cur = next;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (!visit[i])
			dfs(i);
	}
	if (flag) {
		puts("0");
		return 0;
	}
	while (st.size()) {
		printf("%d\n", st.top());
		st.pop();
	}

	return 0;
}