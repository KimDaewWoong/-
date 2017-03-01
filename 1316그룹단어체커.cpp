#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int n, arr[26], res;
string a;
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	while (n--) {
		memset(arr, 0, sizeof(arr));
		bool p = true;
		cin >> a;
		arr[a[0] - 'a'] = 1;
		for (int i = 1; i < a.size(); i++) {
			if (a[i] != a[i - 1]) {
				if (!arr[a[i] - 'a']) {
					arr[a[i] - 'a']++;
				}
				else {
					p = false;
					break;
				}
			}
		}
		if (p) res++;
	}
	cout << res;
	return 0;
}