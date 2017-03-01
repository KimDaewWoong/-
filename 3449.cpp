#include<cstdio>
#include<iostream>
#include<string>

using namespace std;

int t, c;
string n, m;

int main() {

	freopen("input.txt", "r", stdin);

	scanf("%d", &t);
	while (t--) {
		cin >> n >> m;
		for (int i = 0; i < n.length(); i++) {
			if (n[i] != m[i]) c++;
		}
		printf("Hamming distance is %d.\n", c);
		c = 0;
	}
	
	return 0;
}