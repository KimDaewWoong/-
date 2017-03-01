#include<cstdio>
using namespace std;
long long N, cnt;
long long a[1100];

int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%d", &a[i]);
	int b = 1001;
	while (b--) {
		for (int i = 2; i <= N; i++) {
			if (a[1] <= a[i]) {
				a[i]--;
				a[1]++;
				cnt++;
			}
		}
	}
	printf("%d", cnt);
	return 0;
}