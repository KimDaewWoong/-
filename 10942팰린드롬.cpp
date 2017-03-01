#include<cstdio>
using namespace std;
int n, m;
int a[2020], dp[2020][2020];
//dp[x부터][y까지]팰린드롬가능여부 체크

int func(int x, int y) {
	if (x > y) return 1;
	if (dp[x][y]) return 1;
	return dp[x][y] = func(x + 1, y - 1) & a[x]==a[y];
}
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		printf("%d\n", func(x - 1, y - 1));
	}

	return 0;
}