#include<iostream>
#include<cstdio>

using namespace std;
int C(int);
int t, n;
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		printf("%d\n", C(n));
	}

	return 0;
}
int C(int a) {
	if (a == 0) return 1;
	else if (a < 0)	return 0;
	else return C(a - 1) + C(a - 2) + C(a - 3);
}