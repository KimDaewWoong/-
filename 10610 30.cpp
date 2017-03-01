#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

char a[100001];
int l, d, s = 0;
bool b = false;
int main(void) {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	scanf("%s", &a);

	l = strlen(a);
	sort(a, a + l);
	reverse(a, a + l);
	if (a[l - 1] == '0') b = true;
	for (int i = 0; i < l; i++)
		//int형이 됌 int형에선 +'0'하면 char가 됌
		s += (a[i] - '0');

	if (s % 3 == 0 && b) printf("%s\n", a);
	else printf("-1");

	return 0;
}