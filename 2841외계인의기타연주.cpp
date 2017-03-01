#include<cstdio>
#include<stack>
using namespace std;
int n, p, a, b, cnt;
stack <int> st[7];
int main() {
	scanf("%d %d", &n, &p);
	while (n--) {
		scanf("%d %d", &a, &b);
		while (!st[a].empty() && st[a].top() > b) {
			st[a].pop();
			cnt++;
		}
		if (st[a].empty() || st[a].top() != b) {
			st[a].push(b);
			cnt++;
		}
	}
	printf("%d\n", cnt);
	return 0;
}