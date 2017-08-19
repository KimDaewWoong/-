#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int arr[26], temp[26];
pair<int, int> visit[26];
string a, b;
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		memset(visit, 0, sizeof(visit));
		memset(temp, 0, sizeof(temp));
		for (int j = 0; j < a.size(); j++) {
			arr[a[j] - 'a']++;
			visit[a[j] - 'a'].first = 1;
			visit[a[j] - 'a'].second++;
		}
		for (int j = 0; j < b.size(); j++) {
			if (visit[b[j] - 'a'].first && visit[b[j] - 'a'].second >= ++temp[b[j] - 'a']) continue;
			else {
				arr[b[j] - 'a']++;
				visit[b[j] - 'a'].first = 1;
			}
		}

	}
	for (int i = 0; i < 26; i++) cout << arr[i] << "\n";

	return 0;
}