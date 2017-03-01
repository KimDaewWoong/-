#include<cstdio>
using namespace std;
int cnt, min;
bool arr[1010];
int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	while (cnt != k) {
		for (int i = 2; i <= n; i++) {
			if (!arr[i]) {
				arr[i] = true;
				min = i;
				cnt++;
				break;
			}
		}
		if (cnt == k) {
			printf("%d", min);
			return 0;
		}
		for (int j = min*min; j <= n; j += min) {
			if (!arr[j]) {
				arr[j] = true;
				cnt++;
			}
			if (cnt == k) {
				printf("%d", j);
				return 0;
			}
		}
	}
}