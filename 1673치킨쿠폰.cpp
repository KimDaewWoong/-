#include<iostream>
using namespace std;
int n, k, res, q;
int main() {
	freopen("input.txt", "r", stdin);
	while (cin >> n >> k) {
		res = n;
		while (n >= k) {
			res += (n / k);
			n = (n % k) + n / k;
		}
		cout << res << endl;
	}
	return 0;
}