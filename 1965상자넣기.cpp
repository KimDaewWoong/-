#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
int n;
int a[1001];
int dp[1001];
int func(int pos) {
	//기저사례없음
	int& ret = dp[pos];
	if (ret != -1) return ret;
	ret = 1;
	for (int i = 0; i < pos; i++) {
		if (a[i] < a[pos]) ret = max(ret, 1 + func(i));
	}
	return ret;
}


int main() {
	freopen("input.txt", "r", stdin);
	memset(dp, -1, sizeof(dp));
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	a[n] = 65535;
	cout << func(n) - 1;
	return 0;
}