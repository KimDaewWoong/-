#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int a[10010];
int dp[10010][3]; //������ġ, �������θ��� �� ��
int n, sum;
int func(int pos, int cnt) {
	//�������
	if (cnt >= 3) return -987654321;
	if (pos == n) return 0;
	//����ó��
	int& ret = dp[pos][cnt];
	if (ret != -1) return ret;

	return ret = max(func(pos + 1, 0), (a[pos] + func(pos + 1, cnt + 1)));
}

int main() {
	freopen("input.txt", "r", stdin);
	memset(dp, -1, sizeof(dp));
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	printf("%d", func(0, 0));
	return 0;
}