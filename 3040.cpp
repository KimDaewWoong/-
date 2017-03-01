#include<iostream>
#include<cstdio>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	int s = 0;
	int c = 0;
	int a[9];
	for (int i = 0; i < 9; i++) {
		scanf("%d", &a[i]);
		s += a[i];
	}
	c = s - 100;
	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (c == (a[i] + a[j])) {
				for (int k = 0; k < 9; k++) {
					if (k != i && k != j) printf("%d\n", a[k]);
				}
			}
		}
	}

	return 0;
}