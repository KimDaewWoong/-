#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
#include<string>
#include<iostream>
using namespace std;
const int INF = 987654321;
int table[6][6] = { { 10, 8, 7, 5, 0, 1 },{ 8, 6, 4, 3, 0, 1 },{ 7, 4, 3, 2, 0, 1 },{ 5, 3, 2, 2, 0, 1 },{ 0, 0, 0, 0, 0, 0 },{ 1, 1, 1, 1, 0, 0 } };
//╩С го аб ©Л
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0 ,0 };
char arr[55][55];
int n, m;
struct MinCostMaxFlow {
	struct Edge {
		int v, cost, cap, rev;
		Edge(int v, int cost, int cap, int rev) : v(v), cost(cost), cap(cap), rev(rev) {}
	};
	vector<vector<Edge>> vt;
	vector<int> pv, pe;
	int n;
	MinCostMaxFlow(int n) : n(n) {
		vt.resize(n + 1);
		pv.assign(n + 1, -1);
		pe.assign(n + 1, -1);
	}
	void addEdge(int here, int there, int cost, int cap) {
		vt[here].emplace_back(there, -cost, cap, vt[there].size());
		vt[there].emplace_back(here, cost, 0, vt[here].size() - 1);
	}
	bool sfpa(int src, int sink) {
		queue<int> qu;
		vector<int> V(n + 1, 0);
		vector<int> dist(n + 1, INF);
		qu.push(src);
		V[src] = 1;
		dist[src] = 0;
		while (qu.size()) {
			int here = qu.front();
			qu.pop();
			V[here] = 0;
			for (int i = 0; i < vt[here].size(); i++) {
				int there = vt[here][i].v;
				int cap = vt[here][i].cap;
				if (cap && dist[there] > dist[here] + vt[here][i].cost) {
					dist[there] = dist[here] + vt[here][i].cost;
					pv[there] = here;
					pe[there] = i;
					if (!V[there]) {
						qu.push(there);
						V[there] = 1;
					}
				}
			}
		}
		return dist[sink] != INF;
	}

	pair<int, int> sovle(int src, int sink) {
		int flow = 0, cost = 0;
		while (sfpa(src, sink)) {
			int minFlow = INF;
			for (int cur = sink; cur != src; cur = pv[cur]) {
				int prev = pv[cur];
				int idx = pe[cur];
				minFlow = min(minFlow, vt[prev][idx].cap);
			}
			for (int cur = sink; cur != src; cur = pv[cur]) {
				int prev = pv[cur];
				int idx = pe[cur];
				vt[prev][idx].cap -= minFlow;
				vt[cur][vt[prev][idx].rev].cap += minFlow;
				cost += minFlow * vt[prev][idx].cost;
			}
			flow += minFlow;
		}
		return{ flow, -cost };
	}
};
bool IsPossible(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= m) {
		return true;
	}
	return false;
}
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &n, &m);
	MinCostMaxFlow mcmf((n * m + 5) * 2);
	int src = (n*m) * 2 + 2, sink = (n*m) * 2 + 3;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf(" %c", &arr[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if ((i + j) % 2 == 0) {
				mcmf.addEdge(src, i*m + j, 0, 1);
				mcmf.addEdge(i*m + j, sink, 0, 1);
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (IsPossible(nx, ny)) continue;
					int c = table[arr[i][j] - 'A'][arr[nx][ny] - 'A'];
					mcmf.addEdge(i*m + j, nx*m + ny, c, 1);
				}
			}
			else {
				mcmf.addEdge((i*m + j), sink, 0, 1);
			}
		}
	}

	pair<int, int> res = mcmf.sovle(src, sink);
	printf("%d", res.second);
	return 0;
}