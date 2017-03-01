#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
using namespace std;
vector<int>getPi(string p) {
	int m = (int)p.size(), j = 0;
	vector<int> pi(m, 0);
	for (int i = 1; i < m; i++) {
		while (j > 0 && p[i] != p[j])
			j = pi[j - 1];
		if (p[i] == p[j])
			pi[i] = ++j;
	}
	return pi;
}
int main() {
	int n;
	scanf("%d", &n);
	string p;
	cin >> p;
	auto pi = getPi(p);
	cout << n - pi[n-1];

	return 0;
}