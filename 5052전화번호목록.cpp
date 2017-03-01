#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct Trie {
	Trie* next[10];
	bool end;
	Trie() : end(false) {
		memset(next, 0, sizeof(next));
	}
	~Trie() {
		for (int i = 0; i < 10; i++) {
			if (next[i])
				delete next[i];
		}
	}
	void insert(const char* key) {
		if (*key == '\0')
			end = true;
		else {
			int curr = *key - '0';
			if (next[curr] == NULL)
				next[curr] = new Trie();
			next[curr]->insert(key + 1);
		}
	}
	bool find(const char* key) {
		if (*key == '\0')
			return 0;
		if (end)
			return 1;
		int curr = *key - '0';
		return next[curr]->find(key + 1);
	}
};
char a[10000][51];
int main() {
	freopen("input.txt", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--) {
		Trie *root = new Trie;
		int n, r;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%s", &a[i]);
		r = 0;
		for (int i = 0; i < n; i++)
			root->insert(a[i]);
		for (int i = 0; i < n; i++)
			if (root->find(a[i])) {
				r = 1;
			}
		if (r)
			puts("NO");
		else puts("YES");
	}
	return 0;
}