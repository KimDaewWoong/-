#include<cstdio>
using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int h, w, n;
		scanf("%d %d %d", &h, &w, &n);
		if (n%h == 0) {
			printf("%d", h);
			if ((n / h) < 10) printf("0%d", n / h);
			else printf("%d", n / h);
		}
		else { 
			printf("%d", n%h);
			if ((n / h+1) < 10) printf("0%d", n / h+1);
			else printf("%d", n / h+1);
		}
		puts("");
	}
	return 0;
}