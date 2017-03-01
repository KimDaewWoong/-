#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int V, E;
vector<vector<int> > v, G, scc;
vector<int> fr, re;
bool b[10010];

void front(int pos) {
	b[pos] = true;
	for (int i = 0; i < v[pos].size(); i++) {
		if (!b[v[pos][i]]) {
			front(v[pos][i]);
		}
	}
	fr.push_back(pos);
}

void rev(int pos) {
	b[pos] = true;
	re.push_back(pos);
	for (int i = 0; i < G[pos].size(); i++) {
		if (!b[G[pos][i]]) {
			rev(G[pos][i]);
		}
	}
}
int main() {
	scanf("%d %d", &V, &E);
	v.resize(V + 1);
	G.resize(V + 1);
	for (int i = 0; i < E; i++) {
		int st, ed;
		scanf("%d %d", &st, &ed);
		v[st].push_back(ed);
		G[ed].push_back(st);
	}
	memset(b, false, sizeof(b));
	for (int i = 1; i <= V; i++) {
		if (!b[i]) {
			front(i);
		}
	}
	memset(b, false, sizeof(b));
	for (int i = fr.size() - 1; i >= 0; i--) {
		if (!b[fr[i]]) {
			rev(fr[i]);
			sort(re.begin(), re.end());
			scc.push_back(re);
			re.clear();
		}
	}
	sort(scc.begin(), scc.end());
	printf("%d\n", scc.size());
	for (int i = 0; i < scc.size(); i++) {
		for (int j = 0; j < scc[i].size(); j++) {
			printf("%d ", scc[i][j]);
		}
		printf("-1\n");
	}
	return 0;
}