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

	//lowlink를 return 값으로 사용
	int lowlink = id[node];
	for (auto next : from[node]) {
		if (id[next] == 0) {
			//방문하지 않은 정점
			lowlink = min(lowlink, traverse(next));
		}
		else if (groupid[next] == 0) {
			//이미 스택에 들어 있는 정점
			lowlink = min(lowlink, id[next]);
		}
	}

	if (lowlink == id[node]) {
		//그룹추가
		scc.push_back(vector<int >());
		while (1) {
			int now = stack[top - 1];
			top--;

			//node 하위의 서브트리를 scc 그룹으로 묶기
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

		//~x는 n+x
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
	//x와 ~x가 같은 컴포넌트 안에 속하면 답 없음
	for (int v = 1; v <= n; v++) {
		if (groupid[v] == groupid[neg(v)]) {
			puts("0");
			return 0;
		}
	}

	puts("1");
	return 0;
}