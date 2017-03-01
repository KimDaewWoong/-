#include<iostream>
#include<string>
using namespace std;
string a;
int main() {
	freopen("input.txt", "r", stdin);
	while (getline(cin, a)) {
		if (a == "END") return 0;
		string b;
		for (int i = a.size() - 1; i >= 0; i--) b += a[i];
		cout << b << endl;
	}

	return 0;
}