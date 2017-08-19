#include<iostream>
#include<cstring>
using namespace std;
char arr[220][220];
int ap[26];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n * 2; i++)
		cin >> arr[i];
	int cnt = 0;
	for (int i = 0; i < m; i++) {
		memset(ap, 0, sizeof(ap));
		bool flag = 0;
		for (int j = 0; j < n; j++)
			ap[arr[j][i] - 'A'] = 1;
		for (int j = n; j < 2 * n; j++)
			if (ap[arr[j][i] - 'A']) flag = 1;
		if (!flag) cnt++;
	}

	printf("%d", cnt);

	return 0;
}