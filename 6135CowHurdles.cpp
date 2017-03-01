#include<cstdio>
#include<vector>
#include<algorithm>
#define MAXX 987654321
using namespace std;
int n, m, t;
vector<vector<int>> map;
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d %d %d", &n, &m, &t);
	map.resize(n + 1);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			map[i].push_back(MAXX);
			if (i == j) map[i][j] = 0;
		}
	}
	for (int i = 0; i < m; i++) {
		int a, b, w;
		scanf("%d %d %d", &a, &b, &w);
		map[a - 1][b - 1] = w;
	}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					map[k][j] = min(map[k][j] , max(map[k][i], map[i][j]));
			}
		}
	}
	
		for (int i = 0; i < t; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			if (map[a - 1][b - 1] == MAXX) puts("-1");
			else printf("%d\n", map[a - 1][b - 1]);
		}

	return 0;
}