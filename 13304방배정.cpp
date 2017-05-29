#include<cstdio>
#include<algorithm>
using namespace std;
int n, k, p[6];
pair<int, int> pa[1010];
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		pa[i].first = b; //학년
		pa[i].second = a; //성별
	}
	sort(pa, pa + n);
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (pa[i].first == 1 || pa[i].first == 2) p[0]++;
		else if (pa[i].first == 3 || pa[i].first == 4) {
			if (pa[i].second) p[1]++;
			else p[2]++;
		}
		else {
			if (pa[i].second) p[3]++;
			else p[4]++;
		}
	}
	for (int i = 0; i < 5; i++) {
		cnt += p[i] / k;
		if (p[i] % k) cnt++;
	}
	printf("%d", cnt);
	return 0;
}