#include<cstdio>
using namespace std;
int n, k;
char arr[110][110], a;
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf(" %c", &a);
			arr[i][j] = a;
		}
	}
	scanf("%d", &k);
	if (k == 2) {
		for (int i = 0; i < n; i++) {
			for (int j = n - 1; j >= 0; j--) {
				printf("%c", arr[i][j]);
			}
			puts("");
		}
	}
	else if (k == 3) {
		for (int i = n - 1; i >= 0; i--) {
			for (int j = 0; j < n; j++) {
				printf("%c", arr[i][j]);
			}
			puts("");
		}
	}
	else {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				printf("%c", arr[i][j]);
			}
			puts("");
		}
	}

	return 0;
}