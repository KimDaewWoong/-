#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> u, v;
int main() {
	int n, m;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		u.push_back(a);
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int a;
		scanf("%d", &a);
		v.push_back(a);
	}
	sort(u.begin(), u.end());
	for (int i = 0; i < m; i++)
		printf("%d ", binary_search(u.begin(), u.end(), v[i]) ? 1 : 0);
	return 0;
}