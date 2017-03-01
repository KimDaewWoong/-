#include<cstdio>
#include<algorithm>
using namespace std;
int arr[100][100];
int main() {
	for (int i = 0; i < 4; i++) {
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		for (int j = 0; j < c - a; j++) {
			for (int k = 0; k < d - b; k++) {
				arr[a + j][b + k] = 1;
			}
		}
	}
	int cnt = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (arr[i][j]) cnt++;
		}
	}
	printf("%d", cnt);
	return 0;
}