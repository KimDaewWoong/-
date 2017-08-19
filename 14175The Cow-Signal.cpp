#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
char arr[11][11];
string res;
int main() {
	int m, n, k;
	scanf("%d %d %d", &m, &n, &k);
	for (int i = 0; i < m; i++)
		scanf(" %s", arr[i]);
	for (int i = 0; i < m; i++) {
		res = "";
		for (int j = 0; j < n; j++) {
			for (int t = 0; t < k; t++)
				res += arr[i][j];
		}
		for (int t = 0; t < k; t++)
			cout << res << "\n";
	}

	return 0;
}