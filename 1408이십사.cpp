#include<iostream>
#include<string>
using namespace std;
string a, b;
int main() {
	getline(cin, a);
	getline(cin, b);
	int ah, an, as, bh, bn, bs, rh, rn, rs;
	ah = ((a[0] - '0') * 10) + (a[1] - '0');
	an = ((a[3] - '0') * 10) + (a[4] - '0');
	as = ((a[6] - '0') * 10) + (a[7] - '0');
	bh = ((b[0] - '0') * 10) + (b[1] - '0');
	bn = ((b[3] - '0') * 10) + (b[4] - '0');
	bs = ((b[6] - '0') * 10) + (b[7] - '0');
	rh = bh - ah;
	rn = bn - an;
	rs = bs - as;
	if (rs < 0) {
		rs += 60;
		rn--;
	}
	if (rn < 0) {
		rn += 60;
		rh--;
	}
	if (rh < 0) {
		rh += 24;
	}
	if (rh < 10) cout << "0";
	cout << rh << ":";
	if (rn < 10) cout << "0";;
	cout << rn << ":";
	if (rs < 10) cout << "0";;
	cout << rs << endl;

	return 0;
}