#include<iostream>
#include<string>
using namespace std;
string a, b, c, d;
int main() {
	cin >> a >> b >> c >> d;
	a += b;
	c += d;
	cout << atoll(a.c_str()) + atoll(c.c_str());
	return 0;
}