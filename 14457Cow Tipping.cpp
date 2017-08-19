#include<cstdio>
#include<algorithm>
using namespace std;
int arr[11][11];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%1d", &arr[i][j]);
	int cnt = 0;
	for (int i = n - 1; i >= 0; i--) {
		for (int j = n - 1; j >= 0; j--) {
			if (arr[i][j]) {
				cnt++;
				for (int k = 0; k <= i; k++) {
					for (int l = 0; l <= j; l++) {
						arr[k][l] = !arr[k][l];
					}
				}
			}
		}
	}

	printf("%d", cnt);

	return 0;
}