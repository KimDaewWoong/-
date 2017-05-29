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
	void minaddEdge(int here, int there, int cost, int cap) {
		vt[here].emplace_back(there, cost, cap, vt[there].size());
		vt[there].emplace_back(here, -cost, 0, vt[here].size() - 1);
	}
	void maxaddEdge(int here, int there, int cost, int cap) {
		vt[here].emplace_back(there, -cost, cap, vt[there].size());
		vt[there].emplace_back(here, cost, 0, vt[here].size() - 1);
	}
	MinCostMaxFlow(int n) : n(n) {
		vt.resize(n + 1);
		pv.assign(n + 1, -1);
		pe.assign(n + 1, -1);
	}

	bool spfa(int src, int sink) {
		queue<int> qu;
		vector<int> V(n + 1, 0);
		vector<int> dist(n + 1, INF);
		qu.push(src);
		V[src] = 1;
		dist[src] = 0;
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
	int n;
	vector<int> in, out;
	scanf("%d", &n);
	MinCostMaxFlow maxc((n + 2) * 2);
	MinCostMaxFlow minc((n + 2) * 2);
	int src = n + n + 1, sink = n + n + 2;
	for (int i = 1; i <= n; i++) {
		int val;
		scanf("%d", &val);
		in.push_back(val);
		maxc.maxaddEdge(src, i, 0, 1);
		minc.minaddEdge(src, i, 0, 1);
		maxc.maxaddEdge(i + n, sink, 0, 1);
		minc.minaddEdge(i + n, sink, 0, 1);
	}
	for (int i = 1; i <= n; i++) {
		int val;
		scanf("%d", &val);
		out.push_back(val);
	}
	int t, f;
	scanf("%d %d", &t, &f);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int s = out[j - 1] - in[i - 1];
			if (s < 1) continue;
			if (s < t) {
				int c = (s - t) * (s - t);
				if (c > f) c = f;
				maxc.maxaddEdge(i, j + n, c, 1);
				minc.minaddEdge(i, j + n, c, 1);
			}
			else {
				maxc.maxaddEdge(i, j + n, 0, 1);
				minc.minaddEdge(i, j + n, 0, 1);
			}
		}
	}
	sort(in.begin(), in.end());
	sort(out.begin(), out.end());
	for (int i = 0; i < in.size(); i++) {
		if (in[i] < out[i]) continue;
		puts("-1");
		return 0;
	}
	pair<int, int> minr = minc.sovle(src, sink);
	pair<int, int> maxr = maxc.sovle(src, sink);
	printf("%d %d", minr.second, -maxr.second);
	return 0;
}