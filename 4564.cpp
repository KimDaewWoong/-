#include<iostream>
#include<cstdio>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	
	int n, m = 0;
	int sum=1;
	int c = 0;
	scanf("%d", &n);
	if (n != 0) {
		while (1) {
			cout << n << endl;
			while (n) {
				m = n % 10;
				sum *= m;
				n /= 10;
				c++;
			}
			n = sum;
			sum = 1;
			m = 0;
			if (n / 10 == 0) {
				if (c > 1) {
					cout << n << endl;
					c = 0;
				}
				scanf("%d", &n);
				if (n == 0) break;
			}
		}
	}
	return 0;
}