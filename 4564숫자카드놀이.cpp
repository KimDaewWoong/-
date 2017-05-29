#include<iostream>
#include<string>
#include<math.h>
using namespace std;
string a;
int main() {
	while (cin >> a) {
		if (a == "0") return 0;
		while (a.size() != 1) {
			int l = a.size();
			long long res = 1;
			cout << a << " ";
			for (int i = 0; i < a.size(); i++)	res *= (a[i] - '0');
			a = to_string(res);
			if (a.size() == 1) break;
		}
		cout << a << "\n";
	}
	return 0;
}