//MCMF그래프
//MinCost MaxFlow
//유량 - 디닉으로는 안된다. 포드-풀컨슨이용
//벨만포드를 이용한다.
#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

const int INF = 987654321;

struct MinCostMaxFlow {
	//멤버변수
	struct Edge {
		int opp, cost, cap, rev;
		Edge(int opp, int cost, int cap, int rev) : opp(opp), cost(cost), cap(cap), rev(rev) {}
	};

	int n;
	vector<vector<Edge>> node;
	vector<int> pv, pe;
	//생성자
	MinCostMaxFlow(int n) : n(n) {
		pv.assign(n, -1);
		pe.assign(n, -1);
		node.assign(n, vector<Edge>());
	}
	//함수들
	void addEdge(int here, int there, int cost, int cap) {
		//here의 역반향 간선인 there가 몇번째에 있느냐
		node[here].emplace_back(there, cost, cap, (int)node[there].size());//마지막 인자에 size를 가져가는 이유는 rev간선을 채울때 좌표로 찍어주려고 (포인터 쓰기 싫어서 ->빠름)
		node[there].emplace_back(here, -cost, 0, (int)node[here].size() - 1);
	}
	//벨만포드의 개선판 shortest path faster algorithm
	bool spfa(int src, int sink) {
		vector<int> V(n, 0);
		vector<int> dist(n, INF);
		queue<int> q;
		q.push(src);
		dist[src] = 0;
		V[src] = 1;
		while (!q.empty()) {
			int here = q.front();
			V[here] = 0;
			q.pop();

			for (int i = 0; i < node[here].size(); ++i) {
				int there = node[here][i].opp;
				int cap = node[here][i].cap;

				if (cap && dist[there] > dist[here] + node[here][i].cost) {
					dist[there] = dist[here] + node[here][i].cost;
					pv[there] = here;
					pe[there] = i;
					if (!V[there]) { //queue에 들어가있지 않은것만 넣어주고 싶음
						V[there] = 1;
						q.push(there);
					}
				}
			}
		}
		return dist[sink] != INF;
	}
	//여기까지가 MCMF
	pair<int, int> solve(int src, int sink) {
		int flow = 0, cost = 0;
		while (spfa(src, sink)) {
			int minFlow = INF;
			for (int cur = sink; cur != src; cur = pv[cur]) {
				int prev = pv[cur];
				int idx = pe[cur];
				minFlow = min(minFlow, node[prev][idx].cap);
			}
			for (int cur = sink; cur != src; cur = pv[cur]) {
				int prev = pv[cur];
				int idx = pe[cur];
				node[prev][idx].cap -= minFlow;
				//index로 바로 역반향 간선을 접근할 수 있음.
				node[cur][node[prev][idx].rev].cap += minFlow;
				//간선의 비용을 다 음수로 넣어주면 MAX COST를 구할 수있다.
				//최대비용을 구할 때는 cost가 양수가 나오는순간 그만 더하면 된다.
				//최소비용은 그 반대
				cost += node[prev][idx].cost * minFlow;
			}
			flow += minFlow;
		}
		return{ flow,cost };
	}
};

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	MinCostMaxFlow mcmf(n + m + 2);
	int src = n + m, sink = n + m + 1;
	for (int i = 0; i < n; ++i) {
		int r;
		scanf("%d", &r);
		while (r--) {
			int a, b;
			scanf("%d %d", &a, &b);
			--a;
			mcmf.addEdge(i, a + n, b, 1);
		}
	}
	for (int i = 0; i < n; ++i) {
		mcmf.addEdge(src, i, 0, 1);
	}
	for (int i = 0; i < m; ++i) {
		mcmf.addEdge(i + n, sink, 0, 1);
	}
	pair<int, int> ans = mcmf.solve(src, sink);
	printf("%d\n%d", ans.first, ans.second);
	return 0;
}