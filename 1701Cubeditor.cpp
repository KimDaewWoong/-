//suffix array
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
struct Comp {
	bool operator() (const char* a, const char* b) const
	{
		return strcmp(a, b) < 0;
	}
};
int main() {
	char p[5001];
	scanf("%s", &p);
	vector<char*> suff;
	int l = strlen(p);
	for (int i = l - 1; i >= 0; i--)
		suff.push_back(p + i);
	sort(suff.begin(), suff.end(), Comp());
	int maxx = 0;
	for (int i = 0; i < suff.size() - 1; i++) {
		int k = 0;
		while (suff[i][k] == suff[i + 1][k]) k++;
		maxx = max(maxx, k);
	}
	printf("%d\n", maxx);
	return 0;
}