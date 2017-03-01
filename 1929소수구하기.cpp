#include<cstdio>
#define MAXX 1000000
using namespace std;
int n, m;
bool arr[MAXX + 10];
int main() {
	arr[0] = arr[1] = true;
	for (int i = 2; i*i <= MAXX; i++) {
		if (arr[i] == false) {
			for (int j = i*i; j <= MAXX; j = j + i)
				arr[j] = true;
		}
	}
	scanf("%d%d", &n, &m);

	for (int i = n; i <= m; i++) {
		if (!arr[i]) printf("%d\n", i);
	}

	return 0;
}