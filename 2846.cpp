#include<iostream>
#include<cstdio>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);

	int N;
	int a[1010] = { 0 };
	int c = 0;
	int b = 0;
	int d = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= N; i++) {
		if (a[i] > a[i - 1]) {
			b = a[i] - a[i - 1];
			c = c + b;
			if (d < c) d = c;
		}
		else {
			b = 0;
			c = 0;
		}
	}
	if (d != 0) {
		printf("%d", d);
	}
	else printf("0");
	
	return 0;
}