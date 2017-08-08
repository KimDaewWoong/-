#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include<string>
#include<iostream>
using namespace std;
int T;
int arr[10][10] = 
{ { 0, 4, 3, 3, 4, 3, 2, 3, 1, 2 },
{ 4, 0, 5, 3, 2, 5, 6, 1, 5, 4 },
{ 3, 5, 0, 2, 5, 4, 3, 4, 2, 3 },
{ 3, 3, 2, 0, 3, 2, 3, 2, 2, 1 },
{ 4, 2, 5, 3, 0, 3, 4, 3, 3, 2 },
{ 3, 5, 4, 2, 3, 0, 1, 4, 2, 1 },
{ 2, 6, 3, 3, 4, 1, 0, 5, 1, 2 },
{ 3, 1, 4, 2, 3, 4, 5, 0 ,4, 3 },
{ 1, 5, 2, 2, 3, 2, 1, 4, 0, 1 },
{ 2, 4, 3, 1, 2, 1, 2, 3, 1, 0 } };
string seg;
int cnt;
int number;
int Func(int ind, int cnt_t){
	if (cnt_t == 0) return true;
	if (ind > number - 1) return false;
	int From = seg[ind] - 48;
	for (int i = 9; i >= 0; i--)	{
		if (cnt_t - arr[From][i] >= 0)		{
			seg[ind] = i + 48;
			if (Func(ind + 1, cnt_t - arr[From][i])){
				return true;
			}
			seg[ind] = From + 48;
		}
	}
	return false;
}
int main(){
	scanf("%d", &T);
	while (T--){
		scanf("%d", &number);
		cin >> seg;
		scanf("%d", &cnt);
		Func(0, cnt);
		for (int q = 0; q < number; q++)
			printf("%d", seg[q] - 48);
		puts("");
	}
}
