#include<cstdio>
#include<algorithm>
using namespace std;
int arr[4][4];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		arr[a][b]++;
	}
	int res = max(arr[1][2] + arr[2][3] + arr[3][1], arr[1][3] + arr[3][2] + arr[2][1]);
	printf("%d", res);
	return 0;
}