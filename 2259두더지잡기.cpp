#include<cstdio>
#include<algorithm>
using namespace std;
int dp[7000];
int N, S;

pair<int, pair<int, int>> a[7000];
bool tf(int px, int py, int nextx, int nexty, int time1, int time2) {
	//time1 현재 시간, time2 목표지점 시간
	if (time1 < time2) return false;
	if ((long long)((nextx - px)*(nextx - px) + (nexty - py)*(nexty - py)) <= ((long long)(S * (time1 - time2)) * (long long)(S * (time1 - time2)))) return true;
	return false;
}
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &N, &S);
	for (int i = 1; i <= N; i++)	scanf("%d %d %d", &a[i].second.first, &a[i].second.second, &a[i].first);
	a[0] = { 0,{0, 0} };
	sort(a, a + N + 1);
	for (int i = 1; i <= N; i++) {
		int dodo = 0;
		for (int j = 0; j < i; j++) {
			if (j > 0 && dp[j] == 0) continue;
			if (tf(a[j].second.first, a[j].second.second, a[i].second.first, a[i].second.second, a[i].first, a[j].first)) {
				dodo = max(dp[j]+1, dodo);
			}
		}
		dp[i] = dodo;
	}
	for (int i = 1; i <= N; i++)	dp[i]=max(dp[i - 1], dp[i]);
	printf("%d", dp[N]);

	return 0;
}