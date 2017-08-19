#include<iostream>
#include<string>
#include<cstring>
#include<set>
using namespace std;
char arr[1010][220];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n * 2; i++)
		cin >> arr[i];
	int cnt = 0;
	for (int i = 0; i < m - 2; i++) {
		for (int j = i + 1; j < m - 1; j++) {
			for (int k = j + 1; k < m; k++) {
				set<string> st;
				bool flag = false;
				for (int l = 0; l < n; l++) {
					string a;
					a = arr[l][i];
					a += arr[l][j];
					a += arr[l][k];
					st.insert(a);
				}
				for (int l = n; l < 2 * n; l++) {
					string a;
					a = arr[l][i];
					a += arr[l][j];
					a += arr[l][k];
					if (st.count(a)) {
						flag = true;
						break;
					}
				}
				if (!flag) cnt++;
			}
		}
	}

	printf("%d", cnt);

	return 0;
}