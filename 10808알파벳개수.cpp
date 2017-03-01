#include<iostream>
#include<string>
using namespace std;
string a;
int arr[26];
int main() {
	cin >> a;
	for (int i = 0; i < a.size(); i++)	arr[a[i] - 'a']++;
	for (int i = 0; i < 26; i++) cout << arr[i] << " ";

	return 0;
}