#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int n, m;
string k;

int main(void) {

	freopen("input.txt", "r", stdin);
	
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		
		cin >> k;
		m = k.size() - 1;
		m = k[m] - '0';
		if (m % 2 != 0) {
			printf("odd\n");
		}
		else {
			printf("even\n");
		}
	}
	return 0;
}