#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int a[9];
int sum, d;
int e, f;
void func(int b, int c) {
	if (b>=9 || c >= 9) return;

	if (b != c && a[b] + a[c] == sum) {
		e = b;
		f = c;
		return;
	}
	func(b, c + 1);
	func(b + 1, c);

}
int main() {
	freopen("input.txt", "r", stdin);
	for (int i = 0; i < 9; i++) {
		scanf("%d", &a[i]);
		sum += a[i];
	}
	while (sum > 100)	sum -= 100;

	func(0, 1);

	a[e] = 100;
	a[f] = 100;

	sort(a, a + 9);
	for (int i = 0; i < 7; i++)	printf("%d\n", a[i]);

	return 0;
}