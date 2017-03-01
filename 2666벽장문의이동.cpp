#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
//ù��° ���� �� ��ġ, �ι�° ���� �� ��ġ, ���� ������� ���� = �̵�Ƚ��
int dp[25][25][25];
int arr[25], n, lo, hi, l;
int func(int left, int right, int pos) {
	if (pos == l) return 0;
	int& ret = dp[left][right][pos];
	if (ret != -1) return ret;
	return ret = min(abs(left - arr[pos]) + func(arr[pos], right, pos+1), abs(right - arr[pos]) + func(left, arr[pos], pos+1));
}
int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d %d %d %d", &n, &lo, &hi, &l);
	if (lo > hi) swap(lo, hi);
	for (int i = 0; i < l; i++) scanf("%d", &arr[i]);

	printf("%d", func(lo, hi, 0));

	return 0;
}