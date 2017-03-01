#include<iostream>
#include<cstdio>
#include<map>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	long long a, f, tf = 0;
	int n, s, ts = 0;
	map<long long, int> mp;
	scanf("%d", &n);
	while (n--) {
		scanf("%lld", &a);
		mp[a]++;
	}
	for (map<long long, int>::iterator it = mp.begin(); it != mp.end(); it++) {
		
		f = it->first;
		s = it->second;
		if (s > ts) {
			tf = f;
			ts = s;
		}
		else if (s == ts) {
			if (tf > f)	tf = f;
		}

	}
	printf("%lld", tf);
	return 0;
}