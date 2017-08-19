#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int arr[31] = { 1, };
int pos[31] = { 1, };
int main() {
	int temp = 2;
	for (int i = 1; i <= 30; i++) {
		arr[i] = arr[i - 1] * temp;
		pos[i] = arr[i - 1] + arr[i];
	}
	int a, b, res = 0;
	scanf("%d %d", &a, &b);
	if (a == b) {
		puts("0");
		return 0;
	}
	int idx = 0, tog = 1, cur = a, cnt = 0;
	while (1) {
		cnt++;
		cur += (tog * pos[idx]);
		if (a < b)
			if (cur >= b) break;
		if (a > b)
			if (b >= cur) break;
		idx++;
		tog *= -1;
	}
	for (int i = 0; i < cnt; i++)
		res += pos[i];
	res -= abs(cur - b);
	printf("%d", res);
	return 0;
}