#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
int t, N, L;
pair<int, int> arr[2510];
int main() {
	scanf("%d", &t);
	while (t--) {
		vector<int> path;
		vector<int> rev;
		memset(arr, 0, sizeof(arr));
		scanf("%d %d", &N, &L);
		if (L == 1) {
			puts("0");
			continue;
		}
		for (int i = 0; i < L; i++) {
			int val;
			scanf("%d", &val);
			arr[i] = { val, val + 1 };
		}
		int S, E;
		bool flag = false;
		scanf("%d %d", &S, &E);
		int l = S;
		for (int i = 0; i < L - 1; i++) {
			if (arr[i].first - l >= 1 || l - arr[i].second >= 1) {
				path.push_back(l);
				continue;
			}
			if (l == arr[i].first) l = arr[i].second;
			else l = arr[i].first;
			path.push_back(l);
		}
		path.push_back(l);
		l = E;
		rev.push_back(l);
		for (int i = L - 1; i > 0; i--) {
			if (arr[i].first - l >= 1 || l - arr[i].second >= 1) {
				rev.push_back(l);
				continue;
			}
			if (l == arr[i].first) l = arr[i].second;
			else l = arr[i].first;
			rev.push_back(l);
		}
		reverse(rev.begin(), rev.end());

		for (int i = 0; i < L; i++) {
			if (abs(path[i] - rev[i]) == 1 && i != L - 1) {
				flag = true;
				break;
			}
		}
		printf("%d\n", flag ? 1 : 0);
	}
	return 0;
}