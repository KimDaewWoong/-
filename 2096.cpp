#include<cstdio>
#include<algorithm>
using namespace std;
int n, a, b, c, x, y, z, q, p, r, i, j, k;
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	while (n--) {
		scanf("%d %d %d", &a, &b, &c);
		q = a; p = b; r = c;

		a += max(x, y);
		b += max(max(x, y), z);
		c += max(y, z);
		x = a; y = b; z = c;

		q += min(i, j);
		p += min(min(i, j), k);
		r += min(j, k);
		i = q; j = p; k = r;
	}
	printf("%d\n", max(max(x, y), z));
	printf("%d\n", min(min(i, j), k));
	return 0;
}