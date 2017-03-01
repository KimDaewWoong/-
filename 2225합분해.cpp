#include<cstdio>
#include<cstring>
using namespace std;
int n, k, s;
int a[210];
int dp[210][210];

int main() {
	freopen("input.txt", "r", stdin);
	memset(dp, -1, sizeof(dp));
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) a[i] = i;



	return 0;
}


//dp[cnt-1][n-1]+dp[cnt-1][n-2]+...+dp[cnt-1][0]

/*int sol(int p, int q){
if(q==r)	return 1;
int& ret = dp[p][q]
if(ret != -1) return ret;
int tmp=0;
for(int i=p; i>-=0; --i){
tmp+=sol(i,q-1);
tmp%1000000000
}
return ret=tmp;
}
*/