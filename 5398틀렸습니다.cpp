#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
char arr[2020][2020];
int t, h, v, x, y, b[1001], num[2020][2020];
bool vt[1001];
vector<vector<int >> a;
int dfs(int here) {
	if (vt[here]) return 0;
	vt[here] = 1;
	for (int i = 0; i < a[here].size(); i++) {
		int there = a[here][i];
		if (!b[there] || dfs(b[there])) {
			b[there] = here;
			return 1;
		}
	}
	return 0;
}
int func() {
	memset(b, 0, sizeof(b));
	int result = 0;
	for (int i = 1; i <= h; i++) {
		memset(vt, false, sizeof(vt));
		if (dfs(i)) result++;
	}
	return result;
}
int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &h, &v);
		memset(arr, 0, sizeof(arr));
		memset(num, 0, sizeof(num));
		a.resize(h + v);
		for (int i = 1; i <= h; i++) {
			char q[1001] = { 0, };
			scanf("%d %d %s", &x, &y, &q);
			for (int j = x; j < x + strlen(q); j++) {
				arr[j][y] = q[j - x];
				num[j][y] = i;
			}
		}
		for (int i = 1; i <= v; i++) {
			char q[1001] = { 0, };
			scanf("%d %d %s", &x, &y, &q);
			for (int j = y; j < y + strlen(q); j++) {
				if (arr[x][j] != 0 && arr[x][j] != q[j - y]) {
					a[i].push_back(num[x][j]);
				}
			}
		}
		printf("%d\n", h + v - func());
		a.clear();
	}
	return 0;
}