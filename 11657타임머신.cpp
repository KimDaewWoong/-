//벨만-포드 알고리즘
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#define INF 0x3F3F3F3F
using namespace std;
int main() {
	int N, M, dist[500];
	scanf("%d %d", &N, &M);
	vector<pair<int, int> > adj[500];
	for (int i = 0; i < M; i++) {
		int A, B, C;
		scanf("%d %d %d", &A, &B, &C);
		adj[A - 1].push_back({B - 1, C});
	}
	bool minusCycle = false;
	memset(dist, 0x3F, sizeof(dist));
	dist[0] = 0;
	for (int i = 0; i<N; i++) { // (N-1) + 1번의 루프. 마지막은 음의 싸이클 존재 여부 확인용
		for (int j = 0; j<N; j++) {
			// N-1번의 루프에 걸쳐 각 정점이 i+1개 정점을 거쳐오는 최단경로 갱신
			for (auto &p : adj[j]) {
				int next = p.first, d = p.second;
				if (dist[j] != INF && dist[next] > dist[j] + d) {
					dist[next] = dist[j] + d;
					// N번째 루프에 값이 갱신되면 음의 싸이클이 존재한다.
					if (i == N - 1) minusCycle = true;
				}
			}
		}
	}
	if (minusCycle) puts("-1");
	else {
		for (int i = 1; i<N; i++)
			printf("%d\n", dist[i] != INF ? dist[i] : -1);
	}
	return 0;
}