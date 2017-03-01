#include<iostream>
#include<string>
using namespace std;
string a, b;
string arr[8] = { "000", "001", "010", "011", "100", "101", "110", "111" };
int main() {
	cin >> a;
	int i = 0;
	if (a[0] - '0' <= 3) {
		i = 1;
		switch (a[0]) {
		case '0':
			b = "0";
			break;
		case '1':
			b = "1";
			break;
		case '2':
			b = "10";
			break;
		case '3':
			b = "11";
			break;
		}
	}
	for (; i < a.size(); i++) {
		b += arr[a[i] - '0'];
	}
	cout << b << endl;
	return 0;
}