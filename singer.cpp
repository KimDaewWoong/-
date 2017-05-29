#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
int t, n, m, indegree[1010];
bool arr[1010][1010];
int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);
		memset(indegree, 0, sizeof(indegree));
		memset(arr, false, sizeof(arr));
		for (int i = 0; i < m; i++) {
			int cnt, prev, cur;
			scanf("%d", &cnt);
			scanf("%d", &prev);
			for (int j = 1; j < cnt; j++) {
				scanf("%d", &cur);
				arr[prev][cur] = true;
				prev = cur;
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (arr[i][j]) indegree[j]++;
			}
		}
		priority_queue<int> pq;
		for (int i = 1; i <= n; i++) {
			if (!indegree[i]) {
				pq.push(-i);
			}
		}
		int result[1010] = { 0, };
		bool flag = false;
		for (int i = 1; i <= n; i++) {
			if (pq.empty()) {
				printf("0");
				flag = true;
				break;
			}
			int here = -pq.top();
			pq.pop();
			result[i] = here;
			for (int j = 1; j <= n; j++) {
				if (!arr[here][j]) continue;
				indegree[j]--;
				if (!indegree[j]) {
					pq.push(-j);
				}
			}
		}
		if (!flag) {
			for (int i = 1; i <= n; i++) printf("%d ", result[i]);
		}
		puts("");
	}
	return 0;
}