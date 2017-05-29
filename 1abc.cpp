#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 1332;
int money = 1000000;
int change[6] = { 100, 50, 20, 10, 5, 1 };
int a[6];
int total;
int main() {
	for (int i = 0; i < 6; i++) {
		change[i] *= N;
		total += change[i];
	}
	//지폐별로 1장 이상씩
	if (money > total) {
		money -= total;
		for (int i = 0; i < 6; i++) a[i]++;
	}
	money -= (change[0] * 3);	a[0] += 3;
	money -= (change[1] * 3);	a[1] += 3;
	money -= (change[2] * 19);	a[2] += 19;
	int main_index = 2;
	int index = 2;
	int abc = 0;
	while (money > 2000 && money > 0) {
		if (money < change[main_index]) main_index++;
		for (int i = main_index; i < 6; i++) abc += change[i];
		int div = money / abc;
		int mod = money % abc;
		if (mod <= 2000) {

		}
		for (int i = 0; i < div; i++) {
			for (int j = main_index; j < 6; j++) {
				a[j]++;
			}
		}
	}
	return 0;
}