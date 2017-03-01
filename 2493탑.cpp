#include<cstdio>
#include<stack>
using namespace std;
int n, val;
stack<pair<int, int>> st;
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &val);
		while (!st.empty()) {
			if (val < st.top().second) {
				printf("%d ", st.top().first);
				break;
			}
			st.pop();
		}
		if (st.empty()) printf("0 ");
		st.push({ i, val });
	}
	return 0;
}