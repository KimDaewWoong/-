#include<iostream>
#include<cstdio>
#include<set>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	int N, a;
	set<int> st;
	scanf("%d", &N);
	while (N--) {
		scanf("%d", &a);
		st.insert(a);
	}
	for (set<int>::iterator it = st.begin(); it != st.end();it++) {
		printf("%d\n", *it);
	}

	return 0;
}