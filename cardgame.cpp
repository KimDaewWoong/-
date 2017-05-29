#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
int arr[220][220], cnt[220];
int t, n, m, total;
int main() {
	scanf("%d", &t);
	while (t--) {
		memset(arr, 0, sizeof(arr));
		memset(cnt, 0, sizeof(cnt));
		scanf("%d %d", &n, &m);
		total = 2 * n - 1;
		getchar();
		for (int i = 1; i <= m; i++) {
			int temp = 0;
			string str;
			getline(cin, str);
			for (int j = 0; j <= str.size(); j++) {
				if (str[j] != ' ' && j != str.size()) {
					temp *= 10;
					temp += str[j] - '0';
					continue;
				}
				else {
					if (!arr[i][temp]) {
						arr[i][temp] = 1;
						cnt[i]++;
					}
					else {
						arr[i][temp] = 0;
						cnt[i]--;
						total -= 2;
					}
					temp = 0;
				}
			}
		}

		while (1) {
			for (int i = 1; i <= m; i++) {
				if (total == 1) break;
				if (!cnt[i]) continue;
				int j = i;
				while (1) {
					j = (j + 1) % (m + 1);
					if (!cnt[j]) continue;
					if (cnt[j] <= i) {
						for (int k = n; k > 0; --k) {
							if (arr[j][k] == 1) {
								arr[j][k] = 0;
								cnt[j]--;
								if (arr[i][k] == 1) {
									arr[i][k] = 0;
									cnt[i]--;
									total -= 2;
								}
								else {
									arr[i][k] = 1;
									cnt[i]++;
								}
								break;
							}
						}
					}
					else {
						int pos = 0;
						for (int k = 1; k <= n; k++) {
							if (arr[j][k]) {
								pos++;
								if (pos == i) {
									arr[j][k] = 0;
									cnt[j]--;
									if (arr[i][k]) {
										arr[i][k] = 0;
										cnt[i]--;
										total -= 2;
									}
									else {
										arr[i][k] = 1;
										cnt[i]++;
									}
									break;
								}
							}
						}
					}
					break;
				}
			}
			if (total == 1) break;
		}
		for (int i = 1; i <= m; i++) {
			if (cnt[i]) {
				printf("%d\n", i);
				break;
			}
		}
	}
	return 0;
}