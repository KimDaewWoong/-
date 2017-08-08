#include<cstdio>
#include<cstring>
#include<algorithm>
#define INF 0x3F3F3F3F
using namespace std;
int n, m, arr[550][550], a, b;
int res[550];
int main() {
	freopen("input.txt", "r", stdin);
	memset(arr, INF, sizeof(arr));

	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		arr[a][b] = 1;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
			}
		}
	}

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (arr[i][j] != INF) {
				if (++res[i] == n - 1) cnt++;
				if (++res[j] == n - 1) cnt++;
			}
		}
	}

	printf("%d\n", cnt);
	return 0;
}