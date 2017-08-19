#include<cstdio>
#include<algorithm>
using namespace std;
int arr[100100];
int main() {
	int n, k, b;
	scanf("%d %d %d", &n, &k, &b);
	for (int i = 0; i < b; i++) {
		int val;
		scanf("%d", &val);
		arr[val] = 1;
	}
	int sum = 0, cnt = 0, MIN = k;
	for (int i = 1; i <= n; i++) {
		if (sum < k) {
			if (!arr[i]) sum++;
			else {
				sum++;
				cnt++;
			}
		}
		else {
			if (arr[i]) cnt++;
			if (arr[i - k]) cnt--;
		}
		if (sum == k) MIN = min(MIN, cnt);
	}
	printf("%d", MIN);
	return 0;
}