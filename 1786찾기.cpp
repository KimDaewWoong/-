#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
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
vector<int> kmp(string s, string p) {
	vector<int> ans;
	auto pi = getPi(p);
	int n = (int)s.size(), m = (int)p.size(), j = 0;
	for (int i = 0; i < n; i++) {
		while (j > 0 && s[i] != p[j])
			j = pi[j - 1];
		if (s[i] == p[j]) {
			if (j == m - 1) {
				ans.push_back(i - m + 1);
				j = pi[j];
			}
			else {
				j++;
			}
		}
	}
	return ans;
}

int main() {
	freopen("input.txt", "r", stdin);
	string s, p;
	getline(cin, s);
	getline(cin, p);
	auto matched = kmp(s, p);
	printf("%d\n", (int)matched.size());
	for (auto i : matched)
		printf("%d\n", i + 1);
	return 0;
}


-------------------------------------------------------------------------------------

#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
string a, b;
vector<int> pi, res;
void getpi() {
	pi.resize(b.length());
	int j = 0;
	for (int i = 1; i < b.length(); i++) {
		while (j > 0 && b[i] != b[j])
			j = pi[j - 1];
		if (b[i] == b[j])
			pi[i] = ++j;
	}
}
void kmp() {
	int j = 0;
	for (int i = 0; i < a.length(); i++) {
		while (j > 0 && a[i] != b[j])
			j = pi[j - 1];
		if (a[i] == b[j]) {
			if (j == b.length() - 1) {
				res.push_back(i - b.length() + 1);
				j = pi[j];
			}
			else
				j++;
		}
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	getline(cin, a);
	getline(cin, b);
	getpi(); kmp();
	printf("%d\n", res.size());
	for (auto i : res)
		printf("%d ", i + 1);
	return 0;
}