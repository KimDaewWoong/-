#include<cstdio>
#include<cstring>
#include<algorithm>
#define INF 0x3F3F3F3F
using namespace std;
int n, m, arr[550][550];
int res[550];
int main() {
	freopen("input.txt", "r", stdin);
	memset(arr, INF, sizeof(arr));

	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
			}
		}
	}

	for (int i = 1; i <= m; i++) {
		int a, b, w;
		scanf("%d %d %d", &a, &b, &w);
		if (arr[a][b] <= w)
			puts("Enjoy other party");
		else
			puts("Stay here");
	}

	return 0;
}