#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define INF 0x3F3F3F3F
using namespace std;
int n, m, arr[110][110], via[110][110];
vector<int> path;
void func(int u, int v) {
	//경유가 없을 경우
	if (via[u][v] == 0) {
		path.push_back(u);
		if (u != v) {
			path.push_back(v);
		}
	}
	//경유가 있을 경우
	else {
		int w = via[u][v];
		func(u, w);
		path.pop_back();
		func(w, v);
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	memset(arr, INF, sizeof(arr));
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b, w;
		scanf("%d %d %d", &a, &b, &w);
		arr[a][b] = min(arr[a][b], w);
	}
	for (int i = 1; i <= n; i++) arr[i][i] = 0;

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (arr[i][j] > arr[i][k] + arr[k][j]) {
					via[i][j] = k;
					arr[i][j] = arr[i][k] + arr[k][j];
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (arr[i][j] != INF)
				printf("%d ", arr[i][j]);
			else
				puts("0");
		}
		puts("");
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) {
				puts("0");
				continue;
			}
			func(i, j);
			printf("%d ", path.size());
			for (int k = 0; k < path.size(); k++)
				printf("%d ", path[k]);
			puts("");

			path.clear();
		}
	}


	return 0;
}