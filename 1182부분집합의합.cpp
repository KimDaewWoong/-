#include<cstdio>
using namespace std;
int n, s, cnt, arr[22];
int func(int num, int sum) {
	if (num == n) return s == sum;
	return func(num + 1, sum) + func(num + 1, sum + arr[num]);
}
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &n, &s);
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	printf("%d", func(0, 0) - (s==0));
	return 0;
}