#include<cstdio>
#include<iostream>
#include<math.h>
//����
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
//f(n,a,b,c) => n���� ������ a���� b�� ���� c�οű�� �̵��� ������ִ� �Լ�
//f(n-1.a,c,b) => n-1���� b�� �ű�
//a c ��� or f(1,a,b,c)
//f(n-1, b, a, c) => b���ִ°����� c�οű�
int f(int n, int a, int b, int c) { 
	//�������
	if (n == 1) {
		printf("%d %d\n", a, c);
		return 0;
	}
	f(n - 1, a, c, b);
	printf("%d %d\n", a, c);
	f(n - 1, b, a, c);
}