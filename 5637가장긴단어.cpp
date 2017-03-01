#include<iostream>
#include<string>
using namespace std;
string a, b;
int main() {
	freopen("input.txt", "r", stdin);
	while (cin >> a) {
		if (a == "E-N-D") break;
		string c;
		for (int i = 0; i < a.size(); i++) {
			if ((a[i] >= 'A' && a[i] <= 'z') || a[i] == '-') {
				c += a[i];
			}
		}
		if (b.size() < c.size()) {
			b = c;
		}
	}
	for (int i = 0; i < b.size(); i++)
		if (b[i] < 'a' && b[i] >= 'A') b[i] += 'a' - 'A';

	cout << b << endl;

	return 0;
}