#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
int n, t;
string a, b;
int dp[110][110];
int func(int, int);
vector <string> v;
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &t);
	while (t--) {
		cin >> a >> n;
		while (n--) {
			memset(dp, -1, sizeof(dp));
			cin >> b;
			if (func(0, 0)) v.push_back(b);
		}
		sort(v.begin(), v.end());
		for (int i = 0; i < v.size(); i++)
			printf("%s\n", v[i].c_str());
		v.clear();
	}
	return 0;
}
int func(int i, int j) {
	if (i == a.size() && j == b.size()) return 1;
	if (i > a.size() || j > b.size()) return 0;
	int& ret = dp[i][j];
	if (ret != -1) return ret;
	ret = 0;
	if (a[i] == '*') return ret = func(i + 1, j) + func(i, j + 1);
	else if (a[i] == '?' || a[i] == b[j]) return func(i + 1, j + 1);
	return 0;
}