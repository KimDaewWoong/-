#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int n;
pair<pair<int, int>, pair<int, string>> pa[100010];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> pa[i].second.second >> pa[i].first.first >> pa[i].first.second >> pa[i].second.first;
		pa[i].first.first *= -1;
		pa[i].second.first *= -1;
	}

	sort(pa, pa + n);

	for (int i = 0; i < n; i++) {
		cout << pa[i].second.second << '\n';
	}

	return 0;
}