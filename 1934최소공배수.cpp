//유클리드 호제법
#include<cstdio>
#include<algorithm>
using namespace std;
int gcd(int a, int b) {
	if (!b) return a;
	gcd(b, a % b);
}
int lcm(int a, int b) {
	return (a * b) / gcd(a, b);
}
int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", lcm(a, b));
	}
	return 0;
}