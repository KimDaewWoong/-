#include<cstdio>
#include<algorithm>
using namespace std;
int n, m, m2, k, val, A[100][100], B[100][100], res[100][100];
int main() {
	freopen("input.txt", "r", stdin);

	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &val);
			A[i][j] = val;
		}
	}

	scanf("%d %d", &m2, &k);
	for (int i = 0; i < m2; i++) {
		for (int j = 0; j < k; j++) {
			scanf("%d", &val);
			B[i][j] = val;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			for (int z = 0; z < m; z++) {
				res[i][j] += A[i][z] * B[z][j];
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			printf("%d ", res[i][j]);
		}
		puts("");
	}


	return 0;
}