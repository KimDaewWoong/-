#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int n, m, stack[20020], top, id[20020], currentid, groupid[20020];
vector<int> from[20020];
vector<vector<int >> scc;
int neg(int x) {
	if (x > n) return x - n;
	else x + n;
}
int func(int node) {
	int lowlink = id[node] = ++currentid;
	stack[top++] = node;

	
}
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		if (a < 0) a = -a + n;
		if (b < 0) b = -b + n;

		from[neg(a)].push_back(b);
		from[neg(b)].push_back(a);
	}
	for (int v = 1; v <= 2 * n; v++) {
		if (id[v] == 0) {
			func(v);
		}
	}

	return 0;
}