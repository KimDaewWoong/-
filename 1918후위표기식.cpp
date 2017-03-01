#include<iostream>
#include<string>
#include<stack>
using namespace std;
stack<char> a;
string s;
int p(char op) {
	if (op == '(' || op == ')') return 0;
	else if (op == '+' || op == '-') return 1;
	else if (op == '*' || op == '/') return 2;
}
int main() {
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
			while (!a.empty() && p(a.top()) >= p(s[i])) {
				cout << a.top();
				a.pop();
			}
			a.push(s[i]);
		}
		else if (s[i] == '(') a.push(s[i]);
		else if (s[i] == ')') {
			while (a.top() != '(') {
				cout << a.top();
				a.pop();
			}
			a.pop();
		}
		else cout << s[i];
	}
	while (!a.empty()) {
		cout << a.top();
		a.pop();
	}
	return 0;
}