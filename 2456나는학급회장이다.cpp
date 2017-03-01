#include<cstdio>
#include<algorithm>
using namespace std;
int n, r;
int arr[4], arr2[4];
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	int a, b, c;
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &a, &b, &c);
		arr[1] += a, arr2[1] += a*a;
		arr[2] += b, arr2[2] += b*b;
		arr[3] += c, arr2[3] += c*c;
	}
	bool T = false;
	r = 1;
	if (arr2[2] > arr2[1]) r = 2;
	else if (arr2[2] == arr2[1]) T = 1;
	if (arr2[3] > arr2[r]) r = 3, T = 0;
	else if (arr2[3] == arr2[r]) T = 1;
	printf("%d %d", T ? 0 : r, arr[r]);
	return 0;
}