#include<iostream>
#include<cstdio>
#include<string>
#include<math.h>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	int m = 0;
	int s = 0;
	string n, a;
	while (cin >> n) a += n;
	
	for (int i = 0; i < a.size(); i++) {
		if (a[i] != ',') m++;
		if (a[i] == ','||i==a.size()-1) {
			if (i == a.size() - 1) i++;
			while (m) {
				s += (a[i - m] - '0')*pow(10, m - 1);
				m--;
			}
		}
	}
	printf("%d", s);
	return 0;
}