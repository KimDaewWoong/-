#include<cstdio>
#include<cstring>
#include<stack>
using namespace std;
int t, n, m, cnt, arr[110];
stack <int> st;

//f(n,a,b,c) => n개의 원판을 a에서 b을 통해 c로옮기는 이동을 출력해주는 함수
//f(n-1.a,c,b) => n-1개를 b로 옮김
//f(n-1,b,a,c) => b에있는값들을 c로옮김
//순차적으로 실행

void f(int n, int a, int b, int c) {
	if (n == 1) {	//1번 처리
		int temp = arr[0];	//1번 원판의 개수
		while (temp--) {
			if (cnt <= m) {
				if (a == 2 && !st.empty()) st.pop(); //2번에서 옮기는거면 pop
				else if (c == 2) st.push(1); //2번으로 들어오는거면 push
				cnt++;
			}
		}
		return;
	}
	f(n - 1, a, c, b); //a의 n-1개를 c를 통해 b로 옮김
	if (cnt > m) return; //기저사례
	int temp = arr[n - 1]; //n번 원판의 개수
	while (temp--) {
		if (cnt <= m) {
			if (a == 2 && !st.empty()) st.pop(); //2번에서 옮기는거면 pop
			else if (c == 2) st.push(n); //2번으로 들어오는거면 push
			cnt++;
		}
	}
	f(n - 1, b, a, c);
}
int main() {
	scanf("%d", &t);
	while (t--) {
		memset(arr, 0, sizeof(arr));
		cnt = 1;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
		scanf("%d", &m);

		f(n, 1, 2, 3);

		if (st.empty()) {
			puts("0");
			continue;
		}

		while (!st.empty()) {
			printf("%d ", st.top());
			st.pop();
		}
		puts("");
	}
	return 0;
}
