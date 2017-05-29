#include<iostream>
#include<string>
using namespace std;
string arr[10] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT", };
int day[15] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, };
int main() {
	int m, d;
	cin >> m >> d;
	for (int i = 2; i <= m; i++)
		day[i - 1] += day[i - 2];
	day[--m] += d;
	cout << arr[day[m] % 7];

	return 0;
}