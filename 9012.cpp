//9012
#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;
int n, c, l, r = 0;
string s;
stack<char> st;
int main(void) {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < s.length(); j++) {
			if (s[j] == ')') {
				r++;
				st.push(')');
			}
			else {
				l++;
				st.push('(');
			}
		}
		if (r != l) printf("NO");
		else {
			st.pop();
			r = 0;
			l = 0;
		}
	}
	return 0;
}