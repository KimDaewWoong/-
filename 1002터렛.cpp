#include<cstdio>
using namespace std;
int n, x_1, x_2, y_1, y_2, r_1, r_2, d1, d2, d3;
int main() {
	scanf("%d", &n);
	while (n--) {
		scanf("%d %d %d %d %d %d", &x_1, &y_1, &r_1, &x_2, &y_2, &r_2);
		d1 = (x_2 - x_1) * (x_2 - x_1) + (y_2 - y_1) * (y_2 - y_1);
		d2 = (r_1 + r_2) * (r_1 + r_2);
		d3 = (r_2 - r_1) * (r_2 - r_1);
		if (!d1 && !d3) puts("-1");
		else {
			if (d1 > d2) puts("0");
			else if (d1 == d2) puts("1");
			else if (d1 < d2) {
				if (d1 == d3) puts("1");
				else if (d1 < d3) puts("0");
				else puts("2");
			}
		}
	}
	return 0;
}