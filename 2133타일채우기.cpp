#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int f[33], g[33];
int n;
int main() {
	scanf("%d", &n);

	f[0] = g[1] = 1; f[1] = g[0] = 0;
	for (int i = 2; i <= n; i++) {
		g[i] = f[i - 1] + g[i - 2];
		f[i] = f[i - 2] + 2 * g[i - 1];
	}

	printf("%d", f[n]);
	return 0;
}