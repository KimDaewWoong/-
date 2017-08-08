#include<cstdio>
#include<algorithm>
using namespace std;
int n, l, arr[1000010];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		int pos = lower_bound(arr + 1, arr + l + 1, x) - arr;
		arr[pos] = x;
		if (pos == l + 1) l++;
	}
	printf("%d", l);
	return 0;
}