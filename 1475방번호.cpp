#include<iostream>
#include<string>
using namespace std;
string a;
int arr[10], cnt;
int main() {
	cin >> a;
	for (int i = 0; i < a.size(); i++)	arr[a[i] - '0']++;
	cnt = (arr[9] + arr[6] + 1) / 2;

	for (int i = 0; i < 9; i++) {
		if (i == 6 || i == 9) continue;
		if (arr[i] > cnt) {
			cnt = arr[i];
		}
	}
	printf("%d\n", cnt);
	return 0;
}