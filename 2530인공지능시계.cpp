#include<cstdio>
using namespace std;
int a, b, c, d;
int main() {
	scanf("%d %d %d %d", &a, &b, &c, &d);
	int h = a, m = b, s = c + d;
	while (s >= 60) {
		s -= 60;
		m++;
		if (m >= 60) {
			m -= 60;
			h++;
			if (h >= 24) {
				h = 0;
			}
		}
	}
	printf("%d %d %d", h, m, s);
	return 0;
}