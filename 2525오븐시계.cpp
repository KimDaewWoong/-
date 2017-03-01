#include<cstdio>
using namespace std;
int a, b, c;
int main() {
	scanf("%d %d %d", &a, &b, &c);
	int h = a, m = b + c;
	while (m >= 60) {
		m -= 60;
		h++;
		if (h >= 24) {
			h = 0;
		}
	}
	printf("%d %d", h, m);
	return 0;
}