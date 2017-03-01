#include<cstdio>
#include<queue>
using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, m;
		scanf("%d %d", &n, &m);
		queue <pair<int, int>> qu;
		priority_queue <int> pq;
		for (int i = 0; i < n; i++) {
			int val;
			scanf("%d", &val);
			qu.push({ val, i });
			pq.push(val);
		}
		int index = 0;
		while (qu.size()) {
			int a = qu.front().first;
			int b = qu.front().second;
			qu.pop();
			if (pq.top() == a) {
				index++;
				pq.pop();
				if (b == m) break;
			}
			else qu.push({ a, b });
		}
		printf("%d\n", index);
	}
	return 0;
}