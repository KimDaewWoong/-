#include<iostream>
#include<string>
using namespace std;
string a, b;
char c;
int an, bn;
int main() {
	freopen("input.txt", "r", stdin);
	cin >> a >> b;
	for (int i = 0; i < a.length(); i++) {
		for (int j = 0; j < b.length(); j++) {
			if (a[i] == b[j]) {
				c = a[i];
				an = i;
				bn = j;
				break;
			}
		}
		if (c != NULL) break;
	}
	for (int i = 0; i < b.length(); i++) {
		for (int j = 0; j < a.length(); j++) {
			if (i == bn) {
				cout << a;
				break;
			}
			if (j == an) cout << b[i];
			else cout << '.';
		}
		cout << endl;
	}

	return 0;
}