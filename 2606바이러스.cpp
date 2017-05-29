#include<cstdio>
#include<cstring>
using namespace std;
int arr[110][110];
int main() {
	memset(arr, -1, sizeof(arr));
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		arr[u - 1][v - 1] = 1;
		arr[v - 1][u - 1] = 1;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (arr[j][i] + arr[i][k] == 2) {
					arr[j][k] = 1;
				}
			}
		}
	}
	int cnt = 0;
	for (int i = 1; i < n; i++) {
		if (arr[0][i] == 1) cnt++;
	}
	printf("%d", cnt);

	return 0;
}