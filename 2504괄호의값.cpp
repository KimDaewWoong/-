#include<cstdio>
#include<iostream>
#include<string>
#include<stack>
using namespace std;
string a;
int res, temp = 1;
stack<char> st;
int main() {
	cin >> a;
	for (int i = 0; i <a.size(); i++) {
		if (a[i] == '(') {
			temp *= 2;
			st.push(a[i]);
			if (a[i + 1] == ')') {
				res += temp;
			}
		}
		else if (a[i] == '[') {
			temp *= 3;
			st.push(a[i]);
			if (a[i + 1] == ']') {
				res += temp;
			}
		}
		else if (a[i] == ')' && st.top() == '(') {
			temp /= 2;
			st.pop();
		}
		else if (a[i] == ']' && st.top() == '[') {
			temp /= 3;
			st.pop();
		}
		else if ((a[i] == ')' || a[i] == ']') && st.empty()) {
			puts("0");
			return 0;
		}
	}
	if (st.empty()) printf("%d", res);
	else puts("0");

	return 0;
}