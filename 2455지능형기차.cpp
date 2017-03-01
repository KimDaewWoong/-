#include<cstdio>
#include<algorithm>
using namespace std;
int a, b, p, arr[10];
int main() {
	freopen("input.txt", "r", stdin);
	int t = 4;
	while (t--) {
		scanf("%d %d", &a, &b);
		p -= a;
		p += b;
		arr[t] = -p;
	}
	t = 4;
	sort(arr, arr + t);
	printf("%d", -arr[0]);
	return 0;
}