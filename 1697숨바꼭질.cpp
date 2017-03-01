#include<cstdio>
#include<queue>
using namespace std;
int bv[100010];
int N, K;
queue<int> qu;
int func(int pos) {
	bv[pos] = 1;
	qu.push(pos);
	while (int s = qu.size()) {
		while (s--) {
			int cpos = qu.front();
			qu.pop();
			if (cpos == K) return bv[cpos] - 1;

			if (cpos - 1 >= 0 && bv[cpos - 1] == 0) {
				bv[cpos - 1] = bv[cpos] + 1;
				qu.push(cpos - 1);
			}
			if (cpos + 1 <= 100000 && bv[cpos + 1] == 0) {
				bv[cpos + 1] = bv[cpos] + 1;
				qu.push(cpos + 1);
			}
			if (2 * cpos <= 100000 && bv[2 * cpos] == 0) {
				bv[2 * cpos] = bv[cpos] + 1;
				qu.push(2 * cpos);
			}
		}
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &N, &K);
	printf("%d", func(N));
	return 0;
}