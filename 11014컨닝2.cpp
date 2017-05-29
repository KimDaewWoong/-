#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
typedef long long ll;
int t, n, m, a, b, bmatch[10010], arr[100][100];
char map[100][100];
bool visited[10010];
//аб, ©Л, ╩Саб, ╩С©Л, гоаб, го©Л
int dx[6] = { -1, 1, -1, 1, -1, 1 };
int dy[6] = { 0, 0, 1, 1, -1, -1 };
vector<vector<int>> vt;
int dfs(int here) {
	if (visited[here]) return 0;
	visited[here] = true;
	for (int i = 0; i < vt[here].size(); i++) {
		int there = vt[here][i];
		if (!bmatch[there] || dfs(bmatch[there])) {
			bmatch[there] = here;
			return 1;
		}
	}
	return 0;
}
int func() {
	memset(bmatch, 0, sizeof(bmatch));
	int res = 0;
	for (int i = 1; i <= a; i++) {
		memset(visited, false, sizeof(visited));
		if (dfs(i)) res++;
	}
	return res;
}
bool isPossible(int x, int y) {
	if (x < 0 || y < 0 || x >= m || y >= n) return false;
	return true;
}
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);
		vt.clear();
		vt.resize((n + 1)*m);
		memset(map, 0, sizeof(map));
		memset(arr, 0, sizeof(arr));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				scanf(" %c", &map[i][j]);
			}
		}
		a = b = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] == '.') {
					if (j % 2) arr[i][j] = ++a;
					else arr[i][j] = ++b;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 1; j < m; j += 2) {
				if (!arr[i][j]) continue;
				for (int k = 0; k < 6; k++) {
					int nx = j + dx[k];
					int ny = i + dy[k];
					if (isPossible(nx, ny) && arr[ny][nx]) {
						vt[arr[i][j]].push_back(arr[ny][nx]);
					}
				}
			}
		}
		printf("%d\n", a + b - func());
	}
	return 0;
}