#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int n, arr[26][26][26][26];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		string str, key;
		cin >> str >> key;
		arr[str[0] - 'A'][str[1] - 'A'][key[0] - 'A'][key[1] - 'A']++;
	}
	int res = 0;
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < 26; j++) {
			for (int k = 0; k < 26; k++) {
				for (int l = 0; l < 26; l++) {
					if (i == k && j == l) continue;
					res += arr[i][j][k][l] * arr[k][l][i][j];
				}
			}
		}
	}

	printf("%d", res / 2);

	return 0;
}