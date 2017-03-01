#include<iostream>
#include<cstdio>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	int T, N;
	int a[6];
	int s = 0;
	int c = 1;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		for (int i = 0; i < 6; i++) {
			scanf("%d", &a[i]);
			s += a[i];
		}
		while (N >= s) {
			c++;
			s = 4 * s;
		}
		printf("%d\n", c);
		s = 0;
		c = 1;
	}
	return 0;
}