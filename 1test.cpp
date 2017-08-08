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
			//���� ��ȣ�� �ִ´�.
			if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
				st.push(str[i]);
				top++;
				continue;
			}
			//stack�� ������� �ʰ� str[i]�� ���� stack�� top�� �ݴ� ��ȣ�̸� �ϼ��� ��ȣ���ڿ��� ���ְ� cnt�� �÷��ش�.
			if (top && (str[i] - st.top() == 2 || str[i] - st.top() == 1)) {
				st.pop();
				top--;
				cnt += 2;
				continue;
			}
			//�߸��� ��ȣ ���ڿ��� ������ stack�� ����ش�.
			else top = 0;

			//stack�� ����� ������ res���� ����.
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