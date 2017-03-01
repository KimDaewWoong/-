//네트워크 플로우 포드-폴컨스
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#define MAXX 52
#define INF 987654321
using namespace std;
int c[MAXX][MAXX], f[MAXX][MAXX];
vector<int> adj[MAXX];
int Ctol(char c) {
	if (c <= 'Z') return c - 'A';
	return c - 'a' + 26;
}
int main() {
	freopen("input.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		char u, v; int w;
		scanf(" %c %c %d", &u, &v, &w);
		u = Ctol(u); v = Ctol(v);
		c[u][v] += w;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int total = 0, S = Ctol('A'), E = Ctol('Z');

	while (1) {
		int prev[MAXX];
		memset(prev, -1, sizeof(prev));
		queue<int> qu;
		qu.push(S);
		while (!qu.empty()) {
			int pos = qu.front();
			qu.pop();
			for (int next : adj[pos]) {
				if (c[pos][next] - f[pos][next] > 0 && prev[next] == -1) {
					qu.push(next);
					prev[next] = pos; //경로를 기억함
					if (next == E) break;
				}
			}
		}
		if (prev[E] == -1) break;
		int flow = INF, i = E;
		while (i != S) {
			flow = min(flow, c[prev[i]][i] - f[prev[i]][i]);
			i = prev[i];
		}
		i = E;
		while (i != S) {
			f[prev[i]][i] += flow;
			f[i][prev[i]] -= flow;
			i = prev[i];
		}
		total += flow;
	}
	printf("%d", total);
	return 0;
}
//디닉
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#define MAXX 55
using namespace std;
int n, s, t, level[MAXX], work[MAXX];
const int S = 0, E = 25;
struct Edge {
	int v, cap, rev;
	Edge(int v, int cap, int rev) : v(v), cap(cap), rev(rev) {}
};
vector<vector<Edge>> vt;

int Ctol(char a) {
	if (a < 'a') return a - 'A';
	return a - 'a' + 26;
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
		if (level[here] + 1 == level[there] && cap>0) {
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
	scanf("%d", &n);
	vt.resize(MAXX);
	for (int i = 0; i < n; i++) {
		char a, b; int c;
		getchar();
		scanf("%c %c %d", &a, &b, &c);
		s = Ctol(a); t = Ctol(b);
		vt[s].push_back(Edge(t, c, (int)vt[t].size()));
		vt[t].push_back(Edge(s, 0, (int)vt[s].size() - 1));
	}
	int ret = 0;
	while (bfs()) {
		memset(work, 0, sizeof(work));
		while (1) {
			int flow = dfs(S, 1001);
			if (!flow) break;
			ret += flow;
		}
	}
	printf("%d", ret);
	return 0;
}