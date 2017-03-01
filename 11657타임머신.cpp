//����-���� �˰���
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
	for (int i = 0; i<N; i++) { // (N-1) + 1���� ����. �������� ���� ����Ŭ ���� ���� Ȯ�ο�
		for (int j = 0; j<N; j++) {
			// N-1���� ������ ���� �� ������ i+1�� ������ ���Ŀ��� �ִܰ�� ����
			for (auto &p : adj[j]) {
				int next = p.first, d = p.second;
				if (dist[j] != INF && dist[next] > dist[j] + d) {
					dist[next] = dist[j] + d;
					// N��° ������ ���� ���ŵǸ� ���� ����Ŭ�� �����Ѵ�.
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