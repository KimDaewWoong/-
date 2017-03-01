#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int N;
vector<int> slice(vector<int> v, int a, int b) {
	return vector<int>(v.begin() + a, v.begin() + b);
}
void preorder(vector<int> inorder, vector<int> postorder) {
	int n = postorder.size();
	if (postorder.empty()) return;
	int root = postorder[n-1];
	int L = find(inorder.begin(), inorder.end(), root) - inorder.begin();
	printf("%d ", root);
	//왼쪽순회결과
	preorder(slice(inorder, 0, L), slice(postorder, 0, L));
	//오른쪽순회결과
	preorder(slice(inorder, L+1, n), slice(postorder, L, n-1));
}
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &N); 
	vector<int> inorder(N);
	vector<int> postorder(N);
	for (int i = 0; i < N; i++) scanf("%d", &inorder[i]);
	for (int i = 0; i < N; i++) scanf("%d", &postorder[i]);
	preorder(inorder, postorder);

	return 0;
}