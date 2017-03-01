#include<cstdio>
#include<iostream>
using namespace std;
int n, a, last=2;
long long p[110] = { 1, 1, 1, };

int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &a);
		if (p[a-1] == 0) {
			for (int i = last + 1; i < a; ++i) {
				p[i] = p[i - 2] + p[i - 3];
			}
			last = a - 1;
		}
		cout << p[a - 1] << endl;
	}
	
	return 0;
}


