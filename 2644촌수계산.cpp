#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
int n, t_x, t_y, t, x, y, cnt;
bool vb[110];
bool tf;
vector <vector<int> > ve;
queue <int> qu;
void func(int pos) {
	qu.push(pos);
	vb[pos] = true;
	while (int s = qu.size()) {
		while (s--) {
			int cpos = qu.front();
			qu.pop();
			if (cpos == t_y) {
				tf = true;
				return;
			}
			for (int i = 0; i < ve[cpos].size(); i++) {
				int npos = ve[cpos][i];
				if (!vb[npos]) {
					vb[npos] = true;
					qu.push(npos);
				}
			}
		}
		cnt++;
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d %d %d %d", &n, &t_x, &t_y, &t);
	ve.resize(n + 1);
	for (int i = 0; i < t; i++) {
		scanf("%d %d", &x, &y);
		ve[x].push_back(y);
		ve[y].push_back(x);
	}
	func(t_x);
	if (!tf) puts("-1");
	else printf("%d", cnt);
	return 0;
}