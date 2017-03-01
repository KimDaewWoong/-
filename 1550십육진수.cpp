#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int n, res;
string a;
int main() {
	cin >> a;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] >= 'A' && a[i] <= 'F') n = a[i] - 'A' + 10;
		else n = a[i] - '0';
		res += n * pow(16, a.size() - i - 1);
	}
	cout << res;

	return 0;
}