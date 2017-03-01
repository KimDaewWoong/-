#include<cstdio>
#include<algorithm>
using namespace std;

int n, t;
int a[501][501];
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	for (int i = n - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			t = max(a[i][j], a[i][j + 1]);
			a[i-1][j] += t;
		}
	}

	printf("%d", a[0][0]);

	return 0;
}