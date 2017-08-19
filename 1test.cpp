#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int MAX = 100001;
int n, m, arr[MAX], pa[MAX][25], lv[MAX], posSize;
bool visit[MAX];
vector<vector<int>> vt;
vector<int> xpos, g;
struct node{
	node* R, *L;
	int val;
	node() : val(0), L(0), R(0) {}

}*seg[MAX];

node *make_tree(node *now, int pos, int val, int x, int y) {
	if (pos < x || y > pos) return now;
	node *ret = new node();
	if (x == y) {
		ret->val = now->val + val;
		return ret;
	}
	int mid = (x + y) >> 1;
	ret->L = make_tree(now->L, pos, val, x, mid);
	ret->R = make_tree(now->R, pos, val, mid + 1, y);
	ret->val = ret->L->val + ret->R->val;
	return ret;
}
int query(node *x, node *y, node *a, node*b, int l, int r, int k) {
	if (l == r) return l;
	int cnt = x->L->val + y->L->val - a->L->val - b->L->val;
	int mid = (l + r) >> 1;
	if(cnt >= k) return query(x->L, y->L, a->L, b->L, l, mid, k);
	else return query(x->R, y->R, a->R, b->R, mid + 1, r, k - cnt);
}
int getPos(int pos) {
	return lower_bound(xpos.begin(), xpos.end(), pos) - xpos.begin();
}
void dfs(int here, int p, int dph) {
	seg[here] = make_tree(seg[p], getPos(g[here]), 1, 1, posSize);
	visit[here] = 1;
	lv[here] = dph;
	for (int i = 0; i < vt[here].size(); i++) {
		int there = vt[here][i];
		if (!visit[there]) {
			pa[there][0] = here;
			dfs(there, here, dph + 1);
		}
	}
}
int lca(int a, int b) {
	if (lv[a] > lv[b]) swap(a, b);
	for (int i = 20; i >= 0; i--) {
		if ((1 << i) <= (lv[a] - lv[b]))
			a = pa[a][i];
		if (a == b) return a;
	}
}
void dfs(int node) {
	visit[node] = true;
}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	return 0;
}