#include<cstdio>
int n, t, idx, val, min, cnt;
int a[100001];

int main() {
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &t);
		for (int i = 0; i < t; i++) {
			scanf("%d %d", &idx, &val);
			a[idx] = val;
		}
		min = a[1]; cnt = 1;
		for (int i = 1; i <= t; i++) {
			if (min > a[i]) {
				min = a[i];
				cnt++;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}