#include<cstdio>
using namespace std;
int arr[50];
int res[100];
int main() {
	arr[0] = 1; arr[1] = 2;
	int b = 1;
	for (int i = 2; i < 28; i++) {
		arr[i] = arr[i - 1] + (i - 1) * b;
		b = b * 2;
	}
	int t, index = 0;

	scanf("%d", &t);
	while (t--) {
		int num;
		scanf("%d", &num);
		for (int i = 2; i < 28; i++) {
			if (arr[i] <= num) continue;
			else {
				index = i-1;
				break;
			}
		}
		int m = 1;
		for (int i = 0; i < index - 1; i++) {
			m *= 2;
		}
		int q = (num - arr[index]) / index;
		int p = (num - arr[index]) % index;
		//2진수가 위치한 곳의 10진수값
		m += q;
		//이진수 변환
		for (int i = index - 1; i >= 0; i--) {
			if ((m % 2) == 1) res[i] = 1;
			else res[i] = 0;
			m /= 2;
		}
		printf("%d\n", res[p]);
	}
	return 0;
}