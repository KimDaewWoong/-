#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int n, m, arr[1010][1010];
bool vi[1010];
void dfs(int a) {
	vi[a] = true;
	for (int i = 1; i <= n; i++) {
		if (arr[a][i] && !vi[i]) {
			dfs(i);
		}
	}
}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		arr[u][v] = arr[v][u] = 1;
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (!vi[i]) {
			dfs(i);
			cnt++;
		}
	}
	printf("%d", cnt);

	return 0;
}