#include<cstdio>
#include<algorithm>
using namespace std;
bool b[1010];
int main() {
	b[0] = b[1] = true;
	for (int i = 2; i*i <= 1010; i++) {
		if (!b[i]) {
			for (int j = i*i; j <= 1010; j += i) {
				b[j] = true;
			}
		}
	}
	int n, cnt = 0;
	scanf("%d", &n);
	while (n--) {
		int val;
		scanf("%d", &val);
		if (!b[val]) cnt++;
	}
	printf("%d", cnt);
	return 0;
}