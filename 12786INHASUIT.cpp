#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#define INF 0x3F3F3F3F
using namespace std;
vector<vector<int>> tree;
int dp[101][21];
int N;
int T;

int find(int idx, int height) {
	if (N == idx)
		return 0;

	int& ret = dp[idx][height];
	if (ret != INF)
		return ret;

	for (int i = 0; i < tree[idx].size(); ++i) {
		int hole = tree[idx][i];
		if (height == hole) {
			ret = min(ret, find(idx + 1, height));
		}
		if (height + 1 == hole) {
			ret = min(ret, find(idx + 1, height + 1));
		}
		if (height - 1 == hole) {
			ret = min(ret, find(idx + 1, height - 1));
		}
		if (height * 2 == hole || (hole == 20 && height >= 10)) {
			int temp = height;
			if (temp >= 10)
				temp = 20;
			else
				temp *= 2;
			ret = min(ret, find(idx + 1, temp));
		}
		ret = min(ret, find(idx + 1, hole) + 1);
	}
	return ret;
}
int main() {
	scanf("%d %d", &N, &T);
	tree.resize(N);
	memset(dp, 0x3F, sizeof(dp));
	for (int i = 0; i < N; ++i) {
		int a, b;
		scanf("%d", &a);
		for (int j = 0; j < a; ++j) {
			scanf("%d", &b);
			tree[i].push_back(b);
		}
	}
	int ret = find(0, 1);
	if (ret > T)
		printf("-1\n");
	else
		printf("%d\n", ret);
	return 0;
}