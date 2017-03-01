#include<iostream>
#include<cstdio>
#include<stack>
#include<string>
using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	int T; scanf("%d", &T);
	string a;
	while (T--) {
		cin >> a;
		stack<char> st;
		for (int i = 0; i < a.length(); i++)
			st.push(a[i]);
		int val = 0;
		bool flag = false;
		while (!st.empty()) {
			if (st.top() == ')')
				val++;
			else 
				val--;
			st.pop();
			if (val < 0) {
				flag = true;
				break;
			}
		}
		if (flag) puts("NO");
		else {
			if (val > 0) puts("NO");
			else puts("YES");
		}
	}
	return 0;
}