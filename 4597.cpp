#include<iostream>
#include<cstdio>
#include<string>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	string n;
	int e = 0;
	int	o = 0;
	while (cin >> n) {
		if (n == "#") break;
		for (int i = 0; i < n.length(); i++) {
			if (n[i] == '1') { o++; printf("%c", n[i]); }
			else if (n[i] == '0') { e++; printf("%c", n[i]); }
			else if(n[i]=='e'){
				if (o % 2 == 0) printf("0\n");
				else printf("1\n");
			}
			else {
				if (o % 2 == 0) printf("1\n");
				else printf("0\n");
			}
		}
		e = 0;
		o = 0;
	}


	return 0;
}