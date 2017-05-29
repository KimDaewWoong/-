#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
const int INF = 987654321;
const int MAXX = 100;
int n, m, val, C[110][110];
struct MinCostMaxFlow {
	struct Edge{
		int v, cost, cap, rev;
		Edge(int v, int cost, int cap, int rev) : v(v), cost(cost), cap(cap), rev(rev) {}
	};
	int n;
	vector<vector<Edge>> vt;
	vector<int> pv, pe;
	
	MinCostMaxFlow(int n) : n(n) {
		pv.assign(n+1, -1);
		pe.assign(n+1, -1);
		vt.assign(n+1, vector<Edge>());

	}
	void addEdge(int here, int there, int cost, int cap) {
		vt[here].emplace_back(there, cost, cap, (int)vt[there].size());
		vt[there].emplace_back(here, -cost, 0, (int)vt[here].size() - 1);
	}
	//시간복잡도 O(VE)이나 (벨만포드랑 똑같음) 보통 O(V+E)로 돌아간다.
	bool spfa(int src, int sink) {
		vector<int> V(n+1, 0);	//queueu에 들어있는지 여부
		vector<int> dist(n+1, INF);
		queue<int> qu;
		qu.push(src);
		dist[src] = 0;
		V[src] = 1;
		while (!qu.empty()) {
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
						V[there] = 1;
						qu.push(there);
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
				cost += minFlow * vt[prev][idx].cost;
			}
			flow += minFlow;
		}
		return{ flow, cost };
	}
};

int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &n, &m);
	MinCostMaxFlow mcmf(n+m+2);
	int src = n + m + 1, sink = n + m + 2;

	for (int i = 1; i <= n; i++) {
		scanf("%d", &val);
		mcmf.addEdge(i + m, sink, 0, val);
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d", &val);
		mcmf.addEdge(src, i, 0, val);
	}
	for (int i = 1; i <= m; i++) 
		for (int j = 1; j <= n; j++) 
			scanf("%d", &C[i][j]);

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &val);
			mcmf.addEdge(i, j + m, val, C[i][j]);
		}
	}

	pair<int, int> res = mcmf.solve(src, sink);
	printf("%d\n%d", res.first, res.second);
	return 0;
}