#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<queue>
#define MAXX 20010
using namespace std;
int n, m, level[MAXX], work[MAXX], ki, kj, S, E;
//╩С го аб ©Л
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };
char arr[110][110];
struct Edge {
	int v, cap, rev;
	Edge(int v, int cap, int rev) : v(v), cap(cap), rev(rev) {}
};
vector<vector<Edge>> vt;
void addEdge(int u, int v, int c) {
	vt[u].emplace_back(v, c, (int)vt[v].size());
	vt[v].emplace_back(u, 0, (int)vt[u].size() - 1);
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
	return  level[E] != -1;
}
int dfs(int here, int curcap) {
	if (here == E) return curcap;
	for (int& i = work[here]; i < vt[here].size(); i++) {
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
bool isPossible(int x, int y) {
	if (x < 0 || y < 0 || x >= m || y >= n) return false;
	return true;
}
int main() {
	scanf("%d %d", &n, &m);
	vt.resize(MAXX);

	for (int i = 0; i < n; i++) {
		getchar();
		for (int j = 0; j < m; j++) {
			scanf("%c", &arr[i][j]);
			if (arr[i][j] == 'K') {
				S = (i*m) + j;
				ki = i; kj = j;
			}
			else if (arr[i][j] == 'H') {
				E = (i*m) + j;
			}
		}
	}
	for (int i = 0; i < 4; i++) {
		int nx = kj + dx[i];
		int ny = ki + dy[i];
		if (isPossible(nx, ny) && arr[ny][nx] == 'H') {
			puts("-1");
			return 0;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == '#') continue;
			addEdge((i*m) + j, (i*m) + j + (n*m), 1);
			for (int k = 0; k < 4; k++) {
				int nx = j + dx[k];
				int ny = i + dy[k];
				if (isPossible(nx, ny) && arr[ny][nx] != '#') {
					addEdge((i*m) + j + (n*m), (ny*m) + nx, 987654321);
				}
			}
		}
	}
	int ret = 0;
	while (bfs()) {
		memset(work, 0, sizeof(work));
		while (1) {
			int flow = dfs(S + (n*m), 987654321);
			if (!flow) break;
			ret += flow;
		}
	}
	printf("%d", ret);
	return 0;
}