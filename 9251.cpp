#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;

int alen, blen;
char a[1005];
char b[1005];
int dp[1005][1005];

int func(int i, int j) {
	if (alen == i || blen == j) return 0;
	int& ret = dp[i][j];
	if (ret != -1) return ret;
	if (a[i] == b[j]) return ret = 1 + func(i + 1, j + 1);
	return ret = max(func(i + 1, j), func(i, j + 1));
}

int main() {
	freopen("input.txt", "r", stdin);
	memset(dp, -1, sizeof(dp));
	cin >> a >> b;
	alen = strlen(a);
	blen = strlen(b);

	cout << func(0, 0);

	return 0;
}