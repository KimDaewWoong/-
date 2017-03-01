#include<iostream>
#include<string>
using namespace std;
string a, b;
char res[10010];
int main() {
	freopen("input.txt", "r", stdin);
	cin >> a >> b;
	int al = a.size() - 1;
	int bl = b.size() - 1;
	int c = 0, p = 10001;
	while (al > -1 || bl > -1 || c) {
		if (al > -1) c += a[al--] - '0';
		if (bl > -1) c += b[bl--] - '0';
		res[--p] = c % 10 + '0';
		c /= 10;
	}
	cout << res + p;
	return 0;
}