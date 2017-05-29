#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
const int INF = 987654321;
struct MinCostMaxFlow {
	struct Edge {
		int v, cost, cap, rev;
		Edge(int v, int cost, int cap, int rev) : v(v), cost(cost), cap(cap), rev(rev) {}
	};
	int n;
	vector<vector<Edge>> vt;
	vector<int> pv, pe;
	void addEdge(int here, int there, int cost, int cap) {
		vt[here].emplace_back(there, cost, cap, vt[there].size());
		vt[there].emplace_back(here, -cost, 0, vt[here].size() - 1);
	}
	MinCostMaxFlow(int n) : n(n) {
		vt.resize(n + 1);
		pv.assign(n + 1, -1);
		pe.assign(n + 1, -1);
	}

	bool spfa(int src, int sink) {
		queue<int> qu;
		vector<int> V(n + 1, 0);
		vector<int>dist(n + 1, INF);
		V[src] = 1;
		dist[src] = 0;
		qu.push(src);
		while (qu.size()) {
			int here = qu.front();
			V[here] = 0;
			qu.pop();
			for (int i = 0; i < vt[here].size(); i++) {
				int there = vt[here][i].v;
				int cap = vt[here][i].cap;
				if (cap && dist[there] > dist[here] + vt[here][i].cost) {
					dist[there] = dist[here] + vt[here][i].cost;
					pv[there] = here;
					pe[there] = i;
					if (!V[there]) {
						V[there] = 1;
						qu.push(there);
					}
				}
			}
		}
		return dist[sink] != INF;
	}

	pair<int, int> sovle(int src, int sink) {
		int flow = 0, cost = 0;
		while (spfa(src, sink)) {
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
		return{ flow, cost };
	}
};
int main() {
	freopen("input.txt", "r", stdin);
	int n, m;
	scanf("%d %d", &n, &m);
	MinCostMaxFlow mcmf(n + 3);
	int src = n + 2, sink = n + 3;
	mcmf.addEdge(src, 1, 0, 2);
	mcmf.addEdge(n, sink, 0, 2);
	for (int i = 1; i <= m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		mcmf.addEdge(a, b, c, 1);
		mcmf.addEdge(b, a, c, 1);
	}
	pair<int, int> res = mcmf.sovle(src, sink);
	printf("%d", res.second);
	return 0;
}