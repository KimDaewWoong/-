#include<iostream>
#include<string>
#include<cstring>
#include<map>
#include<set>
using namespace std;
int n;
map<string, int> mp;
map<string, int>::iterator it;
set<int> st;
set<int>::iterator sit;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		string a; int b;
		cin >> a >> b;
		mp[a] += b;
	}
	it = mp.begin();
	int a = it->second;
	for (it = mp.begin(); it != mp.end(); it++)
		st.insert(it->second);

	sit = st.begin();
	if (st.size() > 1)
		sit++;
	string res = "";
	int cnt = 0;
	for (it = mp.begin(); it != mp.end(); it++) {
		if (*sit == it->second) {
			cnt++;
			res = it->first;
		}
	}

	if (cnt > 1) {
		puts("Tie");
		return 0;
	}
	cout << res << '\n';
	return 0;
}