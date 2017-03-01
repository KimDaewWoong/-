#include<cstdio>
using namespace std;
int n, arr[1010], sum;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		sum += arr[i];
	}
	sum /= 2;
	for (int i = 0; i < n; i++) {
		int temp = 0;
		for (int j = 0; j < n; j += 2)
			temp += arr[(i + j) % n];
		printf("%d\n", temp - sum);
	}
	return 0;
}