#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<stack>
using namespace std;
int t, Case, res, cnt, top;
stack<char> st;
string str;
int main() {
	//freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &t);
	while (t--) {
		cin >> str;
		res = 0;
		top = 0;
		for (int i = 0; i <= str.size(); i++) {
			//여는 괄호는 넣는다.
			if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
				st.push(str[i]);
				top++;
				continue;
			}
			//stack이 비어있지 않고 str[i]가 현재 stack의 top의 닫는 괄호이면 완성된 괄호문자열을 빼주고 cnt를 올려준다.
			if (top && (str[i] - st.top() == 2 || str[i] - st.top() == 1)) {
				st.pop();
				top--;
				cnt += 2;
				continue;
			}
			//잘못된 괄호 문자열이 들어오면 stack을 비어준다.
			else top = 0;

			//stack이 비어져 있으면 res값을 갱신.
			if (!top) {
				res = max(res, cnt);
				cnt = 0;
			}
		}
		printf("Case #%d\n", ++Case);
		printf("%d\n", res);
	}
	return 0;
}