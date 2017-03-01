#include<cstdio>
#include<stack>
using namespace std;
int n, cnt, pos, val;
char res[200001];
stack<int> a;
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	pos = 1;
	while (cnt < 2 * n) {
		scanf("%d", &val);
		while (pos <= val) {
			a.push(pos++);
			res[cnt++] = '+';
		}
		if (val != a.top()) {
			puts("NO");
			return 0;
		}
		res[cnt++] = '-';
		a.pop();
	}
	for (int i = 0; i < cnt; i++)
		printf("%c\n", res[i]);
	return 0;
}