#include<cstdio>
using namespace std;
int fancake[350];
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, maxx = 0, index = 0, minn = 987654321;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &fancake[i]);
			if (maxx < fancake[i]) {
				maxx = fancake[i];
				index = i;
			}
			if (minn > fancake[i]) minn = fancake[i];
		}
		int cnt = 0;
		for (int i = 1; i <= n;) {
			if (fancake[i] == maxx) {
				i++;
				if (i == n) break;
				maxx = -1;
				for (int j = i; j <= n; j++) {
					if (maxx < fancake[j]) {
						maxx = fancake[j];
						index = j;
					}
				}
			}
			else if (maxx == minn) break;
			else {
				if (maxx == fancake[n]) index = i;
				while (maxx != fancake[i]) {
					for (int k = index; k < (((n - index) + 1) / 2) + index; k++) {
						int temp = fancake[k];
						fancake[k] = fancake[(n - k) + index];
						fancake[(n - k) + index] = temp;
					}
					index = i;
					cnt++;
				}
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}