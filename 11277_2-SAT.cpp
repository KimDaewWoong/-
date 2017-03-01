#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int n, m, stack[20020], top, id[20020], currentid, groupid[20020];
vector<int> from[20020];
vector<vector<int> > scc;
int neg(int x) {
	if (x > n) return x - n;
	else return x + n;
}
int traverse(int node) {
	id[node] = ++currentid;
	stack[top++] = node;

	//lowlink�� return ������ ���
	int lowlink = id[node];
	for (auto next : from[node]) {
		if (id[next] == 0) {
			//�湮���� ���� ����
			lowlink = min(lowlink, traverse(next));
		}
		else if (groupid[next] == 0) {
			//�̹� ���ÿ� ��� �ִ� ����
			lowlink = min(lowlink, id[next]);
		}
	}

	if (lowlink == id[node]) {
		//�׷��߰�
		scc.push_back(vector<int >());
		while (1) {
			int now = stack[top - 1];
			top--;

			//node ������ ����Ʈ���� scc �׷����� ����
			groupid[now] = scc.size();
			scc[groupid[now] - 1].push_back(now);

			if (now == node) break;
		}
	}
	return lowlink;
}
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);

		//~x�� n+x
		if (a < 0) a = -a + n;
		if (b < 0) b = -b + n;

		from[neg(a)].push_back(b);
		from[neg(b)].push_back(a);
	}
	for (int v = 1; v <= 2 * n; v++) {
		if (id[v] == 0) {
			traverse(v);
		}
	}
	//x�� ~x�� ���� ������Ʈ �ȿ� ���ϸ� �� ����
	for (int v = 1; v <= n; v++) {
		if (groupid[v] == groupid[neg(v)]) {
			puts("0");
			return 0;
		}
	}

	puts("1");
	return 0;
}