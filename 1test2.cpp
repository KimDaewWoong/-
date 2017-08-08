#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
int n, t;
priority_queue<int> pq;

int main() {
	scanf("%d %d", &n, &t);
	for (int i = 1; i < n; i++) {
		int v;
		scanf("%d", &v);
		pq.push(v);
	}
	int cnt = 0;
	if (n == 1) {
		puts("0");
		return 0;
	}
	while (t <= pq.top()) {
		int temp = pq.top();
		pq.pop();
		temp--;
		pq.push(temp);
		t++;
		cnt++;
	}
	printf("%d", cnt);
	return 0;
}