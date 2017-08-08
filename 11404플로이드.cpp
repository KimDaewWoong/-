#include<cstdio>
#include<cstring>
#include<algorithm>
#define INF 0x3F3F3F3F
using namespace std;
int n, m, arr[110][110];
int main() {
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
				arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
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

	return 0;
}