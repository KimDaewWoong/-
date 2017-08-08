#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int p[300100];
pair<int, int> x[100100], y[100100], z[100100];
vector<pair<int, pair<int, int>>> vt;
int find(int u) {
	if (u == p[u]) return u;
	return p[u] = find(p[u]);
}
bool merge(int u, int v) {
	u = find(u); v = find(v);
	if (u == v) return false;
	p[u] = v;
	return true;
}
int main() {
	freopen("input.txt", "r", stdin);
	int v;
	scanf("%d", &v);
	for (int i = 0; i <= v; i++) p[i] = i;
	for (int i = 0; i < v; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		x[i] = { a, i };
		y[i] = { b, i };
		z[i] = { c, i };
	}
	sort(x, x + v);
	sort(y, y + v);
	sort(z, z + v);

	for (int i = 1; i < v; i++) {
		vt.push_back({ abs(x[i].first - x[i - 1].first),{ x[i].second,  x[i - 1].second } });
		vt.push_back({ abs(y[i].first - y[i - 1].first),{ y[i].second, y[i - 1].second } });
		vt.push_back({ abs(z[i].first - z[i - 1].first),{ z[i].second, z[i - 1].second } });
	}

	sort(vt.begin(), vt.end());

	int res = 0, cnt = 0;
	for (int i = 0; i < vt.size(); i++) {
		if (merge(vt[i].second.first, vt[i].second.second)) {
			res += vt[i].first;
			cnt++;
		}
		if (cnt == v - 1) break;
	}
	printf("%d\n", res);

	return 0;
}