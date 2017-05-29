#include<cstdio>
#include<algorithm>
using namespace std;
int arr[100100];
int main() {
	int n, m;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	sort(arr, arr + n);
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int val;
		scanf("%d", &val);
		int a = lower_bound(arr, arr + n, val) - arr;
		if (arr[a] == val) puts("1");
		else puts("0");
	}

	return 0;
}