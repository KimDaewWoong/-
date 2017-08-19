#include<cstdio>
#include<algorithm>
using namespace std;
pair<int, int> pos[4];
int main() {
	for (int i = 0; i < 4; i++)
		scanf("%d %d", &pos[i].first, &pos[i].second);
	pair<int, int> a, b;
	a.first = min(pos[0].first, pos[2].first);
	a.second = min(pos[0].second, pos[2].second);
	b.first = max(pos[1].first, pos[3].first);
	b.second = max(pos[1].second, pos[3].second);
	int res = max(b.first - a.first, b.second - a.second);
	printf("%d", res*res);

	return 0;
}