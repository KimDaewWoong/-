#include<cstdio>
#include<cmath>
typedef long long ll;
using namespace std;
ll a, b, c, d, e, f;
ll gcd(ll a, ll b) {
	if (!b) return a;
	gcd(b, a % b);
}
int main() {
	scanf("%lld %lld", &a, &b);
	c = sqrt(a);
	d = sqrt(b);
	e = d - c;
	f = b - a;
	if (!e || !f) {
		puts("0");
		return 0;
	}
	ll r = gcd(f, e);
	printf("%lld/%lld", e / r, f / r);
	return  0;
}