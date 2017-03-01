#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int n, b;
long long dp[110];
long long func(int a) {
	//기저사례
	//예외처리
	if (a < 4)	return 1;
	long long& ret = dp[a];
	if (ret != -1) {
		ret = func(a - 2) + func(a - 3);
		return ret;
	}

}

int main() {
	freopen("input.txt", "r", stdin);
	memset(dp, -1, sizeof(dp));
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &b);
		printf("%lld\n", func(b));
	}
	return 0;
}