#include<cstdio>
using namespace std;
int fi[50];
int main() {
	int n;
	fi[0] = 0; fi[1] = 1;
	for (int i = 2; i <= 45; i++) {
		fi[i] = fi[i - 1] + fi[i - 2];
	}
	scanf("%d", &n);
	printf("%d", fi[n]);

	return 0;
}