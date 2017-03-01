#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int n, arr[26];
string a, b;
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	while (n--) {
		memset(arr, 0, sizeof(arr));
		getchar();
		getline(cin, a);
		cin >> b;
		for (int i = 0; i < 26; i++) arr[i] = b[i] - 'A';
		for (int i = 0; i < a.size(); i++) {
			if (a[i] >= 'A' && a[i] < 'a') a[i] = arr[a[i] - 'A'] + 'A';
			cout << a[i];
		}
		cout << endl;
	}
	return 0;
}