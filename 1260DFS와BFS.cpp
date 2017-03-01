#include<cstdio>
int n, m, v, front, rear;
int dfs[1010][1010];
bool dv[1010];//dfs visit
int bfs[1010][1010];
bool bv[1010];//bfs visit
int queue[1010];//bfs queue
void dfsfunc(int pos) {
	dv[pos] = true;//현재 pos 방문
	for (int i = 1; i <= n; i++) {
		if (dfs[pos][i] == 1 && !dv[i]) { //정점연결 and 방문 no
			printf("%d ", i);
			dfsfunc(i);
		}
	}
}
void bfsfunc(int pos) {
	bv[pos] = true;
	queue[rear++] = pos;
	while (front < rear) {
		pos = queue[front++];
		for (int i = 1; i <= n; i++) {
			if (bfs[pos][i] == 1 && !bv[i]) {
				bv[i] = true;
				printf("%d ", i);
				queue[rear++] = i;
			}
		}
	}
}
int main(){
	freopen("input.txt", "r", stdin);
	scanf("%d %d %d", &n, &m, &v);
	while (m--) {
		int i, j;
		scanf("%d %d", &i, &j);
		dfs[i][j] = dfs[j][i] = bfs[i][j] = bfs[j][i] = 1;
	}
	printf("%d ", v);
	dfsfunc(v);
	printf("\n%d ", v);
	bfsfunc(v);
	return 0;
}