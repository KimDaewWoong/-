#include<cstdio>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	int t = n;
	int cnt = 0;
	while (1) {
		cnt++;
		int t1 = (t / 10) + (t % 10);
		int r = (t % 10) * 10 + (t1 % 10);
		if (r == n) break;
		t = r;
	}
	printf("%d", cnt);
	return 0;
}