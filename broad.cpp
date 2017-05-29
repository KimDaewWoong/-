#include<cstdio>
#include<algorithm>
using namespace std;
int t, m, total_time;
pair<int, int> arr[1010];
int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &total_time, &m);
		for (int i = 0; i < m; i++) {
			int s, f;
			scanf("%d %d", &s, &f);
			arr[i].first = f;
			arr[i].second = s;
		}
		sort(arr, arr + m);
		int end_time = -1, cnt = 0;
		for (int i = 0; i < m; i++) {
			if (arr[i].second >= end_time) {
				end_time = arr[i].first;
				cnt++;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}