#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
typedef long long ll;
int t, n, m, car[5050], play[5050], pos;
ll arr[5050][5050], res;
bool visited[5050];
vector<vector<int>> vt;
ll dfs(int here, int s) {
	visited[here] = 1;
	ll abc = 0;
	ll sum = 0;
	for (int i = 0; i < vt[here].size(); i++) {
		int there = vt[here][i];
		if (!visited[there]) {
			abc = dfs(there, s);
			abc += s * play[there];
			sum += abc;
			arr[here][there] += abc;
			res = max(res, arr[here][there] + arr[there][here]);
		}
	}
	return sum;
}
int main() {
	scanf("%d", &t);
	while (t--) {
		memset(play, 0, sizeof(play));
		memset(car, 0, sizeof(car));
		memset(arr, 0, sizeof(arr));
		scanf("%d %d", &n, &m);
		vt.resize(n + 2);
		for (int i = 1; i <= n; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			car[i] = a;
			play[i] = b;
		}
		for (int i = 0; i < m; i++) {
			int u, v;
			scanf("%d %d", &u, &v);
			vt[u].push_back(v);
			vt[v].push_back(u);
		}
		res = 0;

		for (int i = 1; i <= n; i++) {
			memset(visited, false, sizeof(visited));
			dfs(i, car[i]);
		}
		printf("%lld\n", res);
		vt.clear();
	}
	return 0;
}
