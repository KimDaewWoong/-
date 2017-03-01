#include<iostream>
#include<string>
#include<cstring>
using namespace std;
string a;
int n, arr[26];
int main() {
	freopen("input.txt", "r", stdin);
	cin >> n;
	while (n--) {
		int sum = 0;
		memset(arr, 0, sizeof(arr));
		cin >> a;
		for (int i = 0; i < a.size(); i++) arr[a[i] - 'A']++;
		for (int i = 0; i < 26; i++) {
			if (!arr[i]) sum += i + 'A';
		}
		cout << sum << endl;
	}

	return 0;
}