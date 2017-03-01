#include<cstdio>
#include<algorithm>
using namespace std;
int n, m, l, lo, hi, mid;
int arr[220];

int func(int dist) {
	int r = 0;
	for (int i = 1; i < n+2; i++) {
		r += (arr[i] - arr[i - 1] - 1) / dist;
	}
	return r;
}

int main() {
	freopen("input.txt","r", stdin);
	scanf("%d %d %d", &n, &m, &l);
	arr[0] = 0; arr[1] = l;
	for (int i = 2; i < n+2; i++) scanf("%d", &arr[i]);
	sort(arr, arr + n+2);

	hi = l;
	while (lo <= hi) {
		mid = (lo + hi) >> 1;
		if (func(mid) > m) lo = mid + 1;
		else hi = mid - 1;
	}
	printf("%d", lo);
	return 0;
}