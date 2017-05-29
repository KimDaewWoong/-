#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	vector <int> a, b;
	a.resize(n);
	b.resize(n);
	for (int i = 0; i < 2 * n; i++) {
		int val;
		scanf("%d", &val);
		if (i < n) a[i] = val;
		else b[i - n] = -val;
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	int res = 0;
	for (int i = 0; i < n; i++)
		res += a[i] * -b[i];
	printf("%d", res);
	return 0;
}