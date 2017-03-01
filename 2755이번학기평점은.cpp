#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
string a, b;
int n, g, maxx;
double f, fmaxx;
int main() {
	freopen("input.txt", "r", stdin);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> g >> b;
		maxx += g;
		switch (b[0]) {
		case 'A':
			f = 4.0f;
			break;
		case 'B':
			f = 3.0f;
			break;
		case 'C':
			f = 2.0f;
			break;
		case 'D':
			f = 1.0f;
			break;
		case 'F':
			f = 0.0f;
			continue;
		}
		if (b[1] == '+')	f += 0.3f;
		else if (b[1] == '-')	f -= 0.3f;
		fmaxx += f*g;
	}
	double result = fmaxx / maxx;
	printf("%.2f", result);
	return 0;
}