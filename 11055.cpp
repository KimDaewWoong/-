#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;

int n, b, c;
int a[1005];
int dp[1005];

int func(int pos) {
	//기저사례없음. 기저사례 벗어난 범위 호출 안함
	int& ret = dp[pos];
	if (ret != -1) return ret;
	ret = 1;
	for (int i = 0; i < pos; i++) {
		if (a[i] < a[pos]) ret = max(ret, a[i] + func(i));
	}
	return ret;
}

int main() {
	freopen("input.txt", "r", stdin);
	memset(dp, -1, sizeof(dp));
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	a[n] = 1001;
	cout << func(n) - 1;

	return 0;
}