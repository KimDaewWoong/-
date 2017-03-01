#include<cstdio>
#include<algorithm>
using namespace std;
int n, arr[51];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + n);
	printf("%d", arr[0] * arr[n - 1]);
	return 0;
}