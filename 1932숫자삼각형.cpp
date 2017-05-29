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

//#include<cstdio>
//#include<algorithm>
//#include<cstring>
//using namespace std;
//int arr[550][550], dp[550][550], n;
//int func(int y, int x) {
//	if (y > n || x > y || y < 0 || x < 0) return 0;
//	int& ret = dp[y][x];
//	if (ret != -1) return ret;
//	ret = arr[y][x];
//	return ret += max(func(y + 1, x), func(y + 1, x + 1));
//
//}
//int main() {
//	memset(dp, -1, sizeof(dp));
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j <= i; j++) {
//			scanf("%d", &arr[i][j]);
//		}
//	}
//
//	printf("%d\n", func(0, 0));
//	return 0;
//}