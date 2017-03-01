#include<iostream>
#include<cstdio>

using namespace std;

int n;
int a[1000] = { 1, 2 };

int func(int b) {
	
	if (a[b-1] == 0) {
		for (int i = 2; i < b; i++) {
			
			a[i] = (a[i - 1] + a[i - 2])%10007;
		}
	}
	
	return a[b-1] ;
}
int main() {
	int t;

	freopen("input.txt", "r", stdin);

	scanf("%d", &n);
	t=func(n);
	printf("%d", t);
	return 0;
}