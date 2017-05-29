#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int INF = 987654321;
int x[220], y[220], xe[220], ye[220], w[220];
struct MinCostMaxFlow {
	struct Edge {
		int v, cost, cap, rev;
		Edge(int v, int cost, int cap, int rev) : v(v), cost(cost), cap(cap), rev(rev) {}
	};
	int n;
	vector<vector<Edge>> vt;
	vector<int> pv, pe;

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

	pair<int, int> solve(int src, int sink) {
		int flow = 0, cost = 0;
		while (sfpa(src, sink)) {
			int minFlow = INF;
			for (int cur = sink; cur != src; cur = pv[cur]) {
				int prev = pv[cur];
				int index = pe[cur];
				minFlow = min(minFlow, vt[prev][index].cap);
			}
			for (int cur = sink; cur != src; cur = pv[cur]) {
				int prev = pv[cur];
				int index = pe[cur];
				vt[prev][index].cap -= minFlow;
				vt[cur][vt[prev][index].rev].cap += minFlow;
				cost += minFlow * vt[prev][index].cost;
			}
			flow += minFlow;
		}
		return{ flow, cost };
	}
};
int main() {
	freopen("input.txt", "r", stdin);
	int t, n, m;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);
		MinCostMaxFlow mcmf(n + m + 2);
		int src = n + m + 1, sink = n + m + 2;

		for (int i = 1; i <= n; i++) {
			scanf("%d %d %d %d %d", &x[i], &y[i], &xe[i], &ye[i], &w[i]);
			if (x[i] > xe[i]) swap(x[i], xe[i]);
			mcmf.addEdge(src, i, 0, 1);
		}
		for (int j = 1; j <= m; j++) {
			int a, b, c, d, e;
			mcmf.addEdge(j + n, sink, 0, 1);
			scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
			if (b > d) swap(b, d);
			for (int i = 1; i <= n; i++) {
				if ((x[i] <= a && a <= xe[i]) && (b <= y[i] && d >= y[i])) {
					mcmf.addEdge(i, j + n, w[i] * e, 1);
				}
			}
		}
		pair<int, int> res = mcmf.solve(src, sink);
		printf("%d %d\n", res.first, -res.second);
	}
	return 0;
}