#include<cstdio>
#include<queue>
using namespace std;
int bv[10000010];
int N, cnt;
queue<int> qu;
int func(int pos) {
	bv[pos] = 1;
	qu.push(pos);
	while (int s = qu.size()) {
		while (s--) {
			int cpos = qu.front();
			qu.pop();
			if (cpos == 1) return cnt;

			if (cpos % 3 == 0 && bv[cpos % 3] == 0) {
				bv[cpos / 3] = 1;
				qu.push(cpos / 3);
			}
			if (cpos % 2 == 0 && bv[cpos % 2] == 0) {
				bv[cpos / 2] = 1;
				qu.push(cpos / 2);
			}
			if (cpos - 1 >= 1 && bv[cpos - 1] == 0) {
				bv[cpos - 1] = 1;
				qu.push(cpos - 1);
			}
		}
		cnt++;
	}
}
int main() {
	scanf("%d", &N);
	printf("%d", func(N));
	return 0;
}