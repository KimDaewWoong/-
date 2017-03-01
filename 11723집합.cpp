#include<iostream>
#include<cstdio>
#include<set>
#include<map>
#include<cstring>
using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	set<int> st;
	int n, a;
	char ch[20] = { 0 };
	scanf("%d", &n);
	while (n--) {
		scanf("%s", ch);
		if (strcmp(ch, "all") == 0 || strcmp(ch, "empty") == 0) {
			if (strcmp(ch, "all") == 0) {
				for (int i = 1; i <= 20; i++) {
					st.insert(i);
				}
			}
			else {
				for (int i = 1; i <= 20; i++) {
					st.erase(i);
				}
			}
		}
		else {
			scanf("%d", &a);
			if (strcmp(ch, "add") == 0) {
				st.insert(a);
			}
			else if (strcmp(ch, "remove") == 0) {
				st.erase(a);
			}
			else if (strcmp(ch, "check") == 0) {
				printf("%d\n", st.count(a));
			}
			else if (strcmp(ch, "toggle") == 0) {
				if (st.count(a) == 1) st.erase(a);
				else st.insert(a);
			}
		}
	}
	return 0;
}