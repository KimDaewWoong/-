#include<cstdio>
using namespace std;
int arr[41], arr2[41];
int main() {
	int t;
	scanf("%d", &t);
	arr[0] = 1; arr[1] = 0;
	for (int i = 2; i <= t; i++) {
		arr[i] = arr[i - 1] + arr[i - 2];
	}
	arr2[0] = 0; arr2[1] = 1;
	for (int i = 2; i <= t; i++) {
		arr2[i] = arr2[i - 1] + arr2[i - 2];
	}
	while (t--) {
		int n;
		scanf("%d", &n);
		printf("%d %d\n", arr[n], arr2[n]);
	}

	return 0;
}