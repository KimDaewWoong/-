#include<cstdio>
int n, a, b, c;
int main() {
	scanf("%d", &n);
	a = 1; b = 1;
	while (n--) {
		c = a;
		a = (a + b + b) % 9901;
		b = (b + c) % 9901;
	}
	printf("%d", a);
	return 0;
}