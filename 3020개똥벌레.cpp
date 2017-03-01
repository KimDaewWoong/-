//바이너리서치
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n, h, minn, cnt, temp;
		//석순, 종유석
vector<int> down, up;
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &n, &h);
	up.resize(n / 2);
	down.resize(n / 2);
	for (int i = 0; i < n / 2; i++)
		scanf("%d %d", &down[i], &up[i]);
	sort(up.begin(), up.end());
	sort(down.begin(), down.end());
	minn = 500001;
	for (int i = 1; i <= h; i++) {
		temp = n / 2 - (lower_bound(up.begin(), up.end(), h - i + 1) - up.begin());
		temp += n / 2 - (lower_bound(down.begin(), down.end(), i) - down.begin());
		if (temp < minn) {
			cnt = 1; minn = temp;
		}
		else if (temp == minn) cnt++;
	}
	printf("%d %d\n", minn, cnt);
	return 0;
}