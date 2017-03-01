#include<iostream>
#include<string>
using namespace std;
string a;
int main() {
	freopen("input.txt", "r", stdin);
	while (getline(cin, a)) {
		int s = 0, S = 0, n = 0, b = 0;
		for (int i = 0; i < a.size(); i++) {
			if (a[i] < 'a' && 'A' <= a[i]) S++;
			else if (a[i] >= 'a' && 'z' >= a[i]) s++;
			else if (a[i] == ' ') b++;
			else n++;
		}
		cout << s << " " << S << " " << n << " " << b << endl;
	}
	return 0;
}