#include<iostream>
#include<string>
using namespace std;
int n;

int main() {
	freopen("input.txt", "r", stdin);
	while (1) {
		scanf("%d", &n);
		if (!n) return 0;
		string a;
		int res = 0;
		getchar();
		for (int i = 0; i < n; i++) {
			getline(cin, a);
			for (int j = 0; j < a.size(); j++) {
				if (a[j] != ' ' && j != a.size() - 1) continue;
				else if (j >= res) {
					if (j == a.size() - 1) j++;
					res = j;
					break;
				}
			}
		}
		cout << res + 1 << endl;
	}


	return 0;
}