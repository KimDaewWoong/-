#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#define INF 0x3F3F3F3F
using namespace std;
struct ship {
	int x, y, xx, yy, z;
};
ship sh[100100];
int t, n, k, l, segx[3 * 400400], segy[3 * 400400], res[100100];
vector<int> xpos, ypos;
pair<int, int> q[100100];
int update(int *seg, int pos, int val, int node, int l, int r) {
	if (pos < l || pos > r) return seg[node];
	if (l == r) return seg[node] = val;
	int mid = (l + r) >> 1;
	return seg[node] = min(update(seg, pos, val, node * 2, l, mid), update(seg, pos, val, node * 2 + 1, mid + 1, r));
}
int query(int *seg, int lo, int hi, int node, int l, int r) {
	if (lo > r || hi < l) return INF;
	if (lo <= l && hi >= r) return seg[node];
	int mid = (l + r) >> 1;
	return min(query(seg, lo, hi, node * 2, l, mid), query(seg, lo, hi, node * 2 + 1, mid + 1, r));
}
int getPos(vector<int> &vt, int x) {
	return lower_bound(vt.begin(), vt.end(), x) - vt.begin();
}
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &t);
	while (t--) {
		memset(sh, 0, sizeof(sh));
		memset(segx, INF, sizeof(segx));
		memset(segy, INF, sizeof(segy));
		memset(res, 0, sizeof(res));
		memset(q, 0, sizeof(q));
		xpos.clear();
		ypos.clear();
		scanf("%d %d %d", &n, &k, &l);
		for (int i = 0; i < k; i++) {
			scanf("%d %d %d %d %d", &sh[i].x, &sh[i].y, &sh[i].xx, &sh[i].yy, &sh[i].z);
			xpos.push_back(sh[i].x);
			xpos.push_back(sh[i].xx);
			ypos.push_back(sh[i].y);
			ypos.push_back(sh[i].yy);
		}
		for (int i = 0; i < l; i++) {
			scanf("%d %d", &q[i].first, &q[i].second);
			q[i].second ? xpos.push_back(q[i].first) : ypos.push_back(q[i].first);
		}
		sort(xpos.begin(), xpos.end());
		xpos.erase(unique(xpos.begin(), xpos.end()), xpos.end());
		sort(ypos.begin(), ypos.end());
		ypos.erase(unique(ypos.begin(), ypos.end()), ypos.end());

		int xMax = xpos.size();
		int yMax = ypos.size();

		for (int i = l - 1; i >= 0; i--)
			q[i].second ? update(segx, getPos(xpos, q[i].first), i, 1, 0, xMax - 1) : update(segy, getPos(ypos, q[i].first), i, 1, 0, yMax - 1);

		for (int i = 0; i < k; i++) {
			int idx = min(query(segx, getPos(xpos, min(sh[i].x, sh[i].xx)), getPos(xpos, max(sh[i].x, sh[i].xx)), 1, 0, xMax - 1),
				query(segy, getPos(ypos, min(sh[i].y, sh[i].yy)), getPos(ypos, max(sh[i].y, sh[i].yy)), 1, 0, yMax - 1));
			if (idx == INF) continue;
			res[idx] = max(res[idx], sh[i].z);
		}
		for (int i = 0; i < l; i++) printf("%d\n", res[i]);

	}
	return 0;
}