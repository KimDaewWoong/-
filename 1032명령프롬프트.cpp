#include<cstdio>
#include<cstring>
using namespace std;
char arr[55][55], res[55];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%s", arr[i]);
	strcpy(res, arr[0]);
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < strlen(arr[i]); j++) {
			if (!(res[j] == arr[i][j])) res[j] = '?';
		}
	}
	printf("%s", res);
	return 0;
}