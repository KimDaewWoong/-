#include <iostream> 
#include <cstdio> 
#include <algorithm>
#include <cstring>

#define INF -987654321

using namespace std;

int N, M;
int arr[1010][1010];
int dp[2][1010][1010];

int func(int c, int x, int y) {
	if (x > N) return INF;
	if (x == N && y == M)	return arr[x][y];
	if (x == N && c == 0) return INF;
	int& ret = dp[c][x][y];
	if (ret != -1) return ret;
	ret = INF;
	//오른쪽으로 진행
	if (c) {
		if (y < M)  ret = func(c, x, y + 1) + arr[x][y];
	}
	//왼쪽으로 진행
	else {
		if (y > 1) ret = func(c, x, y - 1) + arr[x][y];
	}
	//아래쪽
	ret = max(ret, arr[x][y] + max(func(0, x + 1, y), func(1, x + 1, y)));
	return ret;
}
int main() {
	freopen("input.txt", "r", stdin);
	memset(dp, -1, sizeof(dp));

	cin >> N >> M;
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j)
			cin >> arr[i][j];

	cout << max(func(1, 1, 0), func(1, 1, 1));

	return 0;
}