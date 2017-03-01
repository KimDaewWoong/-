#include<iostream>
#include<cstdio>

using namespace std;

int n, c;

int main() {
	scanf("%d", &n);

	while (n % 5 && n > 0) {
		n -= 3;		
		c++;
	}
	if(n%5!=0)	printf("-1\n");
	else printf("%d", c + n / 5);
	return 0;
}