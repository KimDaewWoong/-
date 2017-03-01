#include<cstdio>
#include<iostream>
#include<math.h>
//김대웅
using namespace std;
int n, s;
int f(int, int, int, int);
int main(void) {
	freopen("input.txt", "r" , stdin);
	scanf("%d", &n);
	s = pow(2, n) - 1;
	printf("%d\n", s);
	f(n, 1, 2, 3);
	return 0;
}
//f(n,a,b,c) => n개의 원판을 a에서 b을 통해 c로옮기는 이동을 출력해주는 함수
//f(n-1.a,c,b) => n-1개를 b로 옮김
//a c 출력 or f(1,a,b,c)
//f(n-1, b, a, c) => b에있는값들을 c로옮김
int f(int n, int a, int b, int c) { 
	//기저사례
	if (n == 1) {
		printf("%d %d\n", a, c);
		return 0;
	}
	f(n - 1, a, c, b);
	printf("%d %d\n", a, c);
	f(n - 1, b, a, c);
}