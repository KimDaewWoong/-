#include<iostream>
#include<cstdio>

using namespace std;
int func(int a) {
	return a*(a + 1) / 2;
}
int N, T, num;
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &N);
	bool ab;
	while (N--) {
		scanf("%d", &T);
		ab = false;
		for (int i = 1; i <45 ; i++) {
			for (int j = i; j <45 ; j++) {
				for (int k = j; k <45 ; k++) {
					if (T == (func(i) + func(j) + func(k))) {
						ab = true;
					}
				}
			}
		}
		if (ab) printf("1\n");
		else printf("0\n");
	}
	return 0;
}