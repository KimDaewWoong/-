#include<iostream>
#include<cstdio>

using namespace std;
int N;
int func(int m) {
	if (m < 0) return 0;
	int a = 0;
	while (m) {
		a += m % 10;
		m /= 10;
	}
	return a;
}

int main() {
	//freopen("input.txt", "r", stdin);
	scanf("%d", &N);
	for(int i = 0; i <= N; i++) {
		if (N == (func(i) + i)) {
			printf("%d", i);
			break;
		}
		if (i==N) {
			printf("0\n");
			break;
		}
	}
	return 0;
}