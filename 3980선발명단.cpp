#include<cstdio>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
int arr[15][15];
const int  INF = 987654321;
struct MinCostMaxFlow {
	struct Edge {
		int v, cost, cap, rev;
		Edge(int v, int cost, int cap, int rev) : v(v), cost(cost), cap(cap), rev(rev) {}
	};
	int n;
	vector<vector<Edge>> vt;
	vector<int> pv, pe;
	MinCostMaxFlow(int n) : n(n) {
		pv.assign(n, -1);
		pe.assign(n, -1);
		vt.assign(n, vector<Edge>());
	}
	void addEdge(int here, int there, int cost, int cap) {
		vt[here].emplace_back(there, cost, cap, (int)vt[there].size());
		vt[there].emplace_back(here, -cost, 0, (int)vt[here].size() - 1);
	}

	bool spfa(int src, int sink) {
		vector<int> V(n, 0);
		vector<int> dist(n, INF);
		queue <int> q;
		q.push(src);
		dist[src] = 0;
		V[src] = 1;
		while (!q.empty()) {
			int here = q.front();
			V[here] = 0;
			q.pop();

			for (int i = 0; i < vt[here].size(); ++i) {
				int there = vt[here][i].v;
				int cap = vt[here][i].cap;

				if (cap && dist[there] > dist[here] + vt[here][i].cost) {
					dist[there] = dist[here] + vt[here][i].cost;
					pv[there] = here;
					pe[there] = i;
					if (!V[there]) {
						V[there] = 1;
						q.push(there);
					}
				}
			}
		}
		return dist[sink] != INF;
	}
	pair<int, int> solve(int src, int sink) {
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
				cost += vt[prev][idx].cost * minFlow;
			}
			flow += minFlow;
		}
		return{ flow, cost };
	}
};
int main() {
	freopen("input.txt", "r", stdin);
	int t, n = 11;
	scanf("%d", &t);
	while (t--) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				scanf("%d", &arr[i][j]);
			}
		}
		MinCostMaxFlow mcmf(2 * n + 3);
		int src = 2 * n + 1, sink = 2 * n + 2;
		for (int i = 1; i <= n; i++) {
			mcmf.addEdge(src, i, 0, 1);
			mcmf.addEdge(i + n, sink, 0, 1);
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (!arr[i][j]) continue;
				mcmf.addEdge(i, j + n, -arr[i][j], 1);
			}
		}
		pair<int, int> res = mcmf.solve(src, sink);
		printf("%d\n", -res.second);
	}
}