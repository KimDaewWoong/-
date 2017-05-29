#include<cstdio>
#include<stack>
using namespace std;
int n, num;
stack<int> st;
int main() {
	scanf("%d", &n);
	int pos = 1;
	for (int i = 0; i < n; i++) {
		scanf("%d", &num);
		if (pos == num) {
			pos++;
			continue;
		}
		while (!st.empty() && st.top() == pos) {
			pos++;
			st.pop();
		}
		st.push(num);
	}
	while (!st.empty()) {
		if (st.top() != pos) {
			puts("Sad");
			return 0;
		}
		pos++;
		st.pop();

	}
	puts("Nice");
	return 0;
}