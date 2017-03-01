#include<cstdio>
struct tree {
	char left, right;
};
struct tree tr[90];
int N;
char node, left, right;
//전위
void func1(char i){
	if (i >= 'A') {
		printf("%c", i);
		func1(tr[i].left);
		func1(tr[i].right);
	}
}
//중위
void func2(char i) {
	if (i >= 'A') {
		func2(tr[i].left);
		printf("%c", i);
		func2(tr[i].right);
	}
}
//후위
void func3(char i) {
	if (i >= 'A') {
		func3(tr[i].left);
		func3(tr[i].right);
		printf("%c", i);
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		getchar();
		scanf("%c %c %c", &node, &left, &right);
		tr[node].left = left;
		tr[node].right = right;
	}
	func1('A');printf("\n");
	func2('A');printf("\n");
	func3('A');printf("\n");
	return 0;
}