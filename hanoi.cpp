#include<cstdio>
#include<cstring>
#include<stack>
using namespace std;
int t, n, m, cnt, arr[110];
stack <int> st;

//f(n,a,b,c) => n���� ������ a���� b�� ���� c�οű�� �̵��� ������ִ� �Լ�
//f(n-1.a,c,b) => n-1���� b�� �ű�
//f(n-1,b,a,c) => b���ִ°����� c�οű�
//���������� ����

void f(int n, int a, int b, int c) {
	if (n == 1) {	//1�� ó��
		int temp = arr[0];	//1�� ������ ����
		while (temp--) {
			if (cnt <= m) {
				if (a == 2 && !st.empty()) st.pop(); //2������ �ű�°Ÿ� pop
				else if (c == 2) st.push(1); //2������ �����°Ÿ� push
				cnt++;
			}
		}
		return;
	}
	f(n - 1, a, c, b); //a�� n-1���� c�� ���� b�� �ű�
	if (cnt > m) return; //�������
	int temp = arr[n - 1]; //n�� ������ ����
	while (temp--) {
		if (cnt <= m) {
			if (a == 2 && !st.empty()) st.pop(); //2������ �ű�°Ÿ� pop
			else if (c == 2) st.push(n); //2������ �����°Ÿ� push
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
