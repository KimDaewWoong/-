#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
using namespace std;
int abc[26];
string word;
int main() {
	cin >> word;
	for (int i = 0; i < word.size(); i++) {
		if (word[i] < 'a') 	abc[word[i] - 'A']++;
		else abc[word[i] - 'a']++;
	}
	int temp[26];
	memcpy(temp, abc, sizeof(abc));
	sort(temp, temp + 26);
	if (temp[25] == temp[24]) {
		puts("?");
		return 0;
	}
	int maxx = temp[25];
	for (int i = 0; i < 26; i++) {
		if (maxx != abc[i]) continue;
		printf("%c", i + 'A');
	}
	return 0;
}
