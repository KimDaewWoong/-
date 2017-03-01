#include<iostream>
#include<cstdio>
#include<string>
#include<map>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	map<string, int> mp;
	int n, m, s, c=0;
	string f, a;
	cin >> n >> m;
	n = n + m;
	while (n--) {
		cin >> a;
		mp[a]++;
	}
	for (map<string, int>::iterator it = mp.begin(); it != mp.end(); it++) {
		s = it->second;
		if (s == 2) {
			c++;
		}
	}
	cout << c << endl;
	for (map<string, int>::iterator it = mp.begin(); it != mp.end(); it++) {
		f = it->first;
		s = it->second;
		if (s==2) {
			cout << f<<endl;
		}
	}
	return 0;
}