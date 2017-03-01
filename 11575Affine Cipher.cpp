#include<iostream>
#include<string>
using namespace std;
int n, a, b;
string s;
int main() {
	freopen("input.txt", "r", stdin);
	cin >> n;
	while (n--) {
		cin >> a >> b >> s;
		for (int i = 0; i < s.size(); i++)
			cout << (char)(((a*(s[i] - 'A') + b) % 26) + 'A');

		cout << endl;
	}
	return 0;
}