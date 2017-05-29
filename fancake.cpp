#include<cstdio>
using namespace std;
int fancake[350];
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, temp = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &fancake[i]);
		}
		int cnt = 0;
		while (1) {
			int ch = 0;
			for (int i = 1; i < n; i++) {
				if (fancake[i - 1] < fancake[i]) {
					temp = fancake[i - 1];
					fancake[i - 1] = fancake[i];
					fancake[i] = temp;
					cnt++;
					ch++;
				}
			}
			if (ch == 0) break;
		}
		printf("%d\n", cnt);
	}
	return 0;
}