#include<cstdio>
#include<algorithm>
using namespace std;
int n, r, a;
int main() {
	scanf("%d", &n);
	r = (6 + (n % 10)) % 10;
	a = (('I' - 'A') + n % 12) % 12;
	a += 'A';
	printf("%c%d", (char)a, r);
	return 0;
}