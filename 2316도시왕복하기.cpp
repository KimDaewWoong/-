#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<queue>
#define MAXX 820
using namespace std;
int n, p, a, b, level[MAXX], work[MAXX];
const int S = 1, E = 2;
struct Edge {
	int v, cap, rev;
	Edge(int v, int cap, int rev) : v(v), cap(cap), rev(rev) {}
};
vector<vector<Edge>> vt;
void addEdge(int u, int v, int c) {
	vt[u].push_back(Edge(v, c, (int)vt[v].size()));
	vt[v].push_back(Edge(u, 0, (int)vt[u].size() - 1));
	return;
}
int bfs() {
	memset(level, -1, sizeof(level));
	queue<int> qu;
	level[S] = 0;
	qu.push(S);
	while (qu.size()) {
		int here = qu.front();
		qu.pop();
		for (int i = 0; i < vt[here].size(); i++) {
			int there = vt[here][i].v;
			int cap = vt[here][i].cap;
			if (level[there] == -1 && cap > 0) {
				level[there] = level[here] + 1;
				qu.push(there);
			}
		}
	}
	return level[E] != -1;
}

int dfs(int here, int curcap) {
	if (here == E) return curcap;
	for (int &i = work[here]; i < vt[here].size(); i++) {
		int there = vt[here][i].v;
		int cap = vt[here][i].cap;
		if (level[here] + 1 == level[there] && cap > 0) {
			int c = dfs(there, min(curcap, cap));
			if (c > 0) {
				vt[here][i].cap -= c;
				vt[there][vt[here][i].rev].cap += c;
				return c;
			}
		}
	}
	return 0;
}

int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &n, &p);
	vt.resize((n + 1) * 2);
	for (int i = 3; i <= n; i++) {
		int u = i * 2, v = u + 1;
		addEdge(u, v, 1);
	}
	for (int i = 0; i < p; i++) {
		scanf("%d %d", &a, &b);
		if (a > b) swap(a, b);
		if (a == 1) addEdge(S, b * 2, 1);
		else if (a == 2) addEdge(b * 2 + 1, E, 1);
		else {
			addEdge(a * 2 + 1, b * 2, 1);
			addEdge(b * 2 + 1, a * 2, 1);
		}
	}
	int ret = 0;
	while (bfs()) {
		memset(work, 0, sizeof(work));
		while (1) {
			int flow = dfs(S, 987654321);
			if (!flow) break;
			ret += flow;
		}
	}
	printf("%d", ret);
	return 0;
}