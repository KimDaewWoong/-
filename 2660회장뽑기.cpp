#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>;
#define INF 0x3F3F3F3F
using namespace std;
int n, m, arr[55][55], a, b;
pair<int, int> res[110];
vector<int> aa;
int main() {
	freopen("input.txt", "r", stdin);
	memset(arr, INF, sizeof(arr));
	scanf("%d", &n);
	while (scanf("%d %d", &a, &b) != EOF && (a != -1 && b != -1)) {
		arr[a][b] = arr[b][a] = 1;
	}
	for (int i = 1; i <= n; i++) arr[i][i] = 0;

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		res[i].second = i;
		for (int j = 1; j <= n; j++) {
			res[i].first = max(res[i].first, arr[i][j]);
		}
	}

	sort(res + 1, res + n);
	int cnt = 1, num = res[1].first;
	aa.push_back(res[1].second);
	for (int i = 2; i <= n; i++) {
		if (num == res[i].first) {
			cnt++;
			aa.push_back(res[i].second);
		}
		else break;
	}
	printf("%d %d\n", num, cnt);
	for (int i = 0; i < aa.size(); i++) {
		printf("%d ", aa[i]);
	}
	return 0;
}