//MCMF�׷���
//MinCost MaxFlow
//���� - ������δ� �ȵȴ�. ����-Ǯ�����̿�
//�������带 �̿��Ѵ�.
#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

const int INF = 987654321;

struct MinCostMaxFlow {
	//�������
	struct Edge {
		int opp, cost, cap, rev;
		Edge(int opp, int cost, int cap, int rev) : opp(opp), cost(cost), cap(cap), rev(rev) {}
	};

	int n;
	vector<vector<Edge>> node;
	vector<int> pv, pe;
	//������
	MinCostMaxFlow(int n) : n(n) {
		pv.assign(n, -1);
		pe.assign(n, -1);
		node.assign(n, vector<Edge>());
	}
	//�Լ���
	void addEdge(int here, int there, int cost, int cap) {
		//here�� ������ ������ there�� ���°�� �ִ���
		node[here].emplace_back(there, cost, cap, (int)node[there].size());//������ ���ڿ� size�� �������� ������ rev������ ä�ﶧ ��ǥ�� ����ַ��� (������ ���� �Ⱦ ->����)
		node[there].emplace_back(here, -cost, 0, (int)node[here].size() - 1);
	}
	//���������� ������ shortest path faster algorithm
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
					if (!V[there]) { //queue�� ������ �����͸� �־��ְ� ����
						V[there] = 1;
						q.push(there);
					}
				}
			}
		}
		return dist[sink] != INF;
	}
	//��������� MCMF
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
				//index�� �ٷ� ������ ������ ������ �� ����.
				node[cur][node[prev][idx].rev].cap += minFlow;
				//������ ����� �� ������ �־��ָ� MAX COST�� ���� ���ִ�.
				//�ִ����� ���� ���� cost�� ����� �����¼��� �׸� ���ϸ� �ȴ�.
				//�ּҺ���� �� �ݴ�
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