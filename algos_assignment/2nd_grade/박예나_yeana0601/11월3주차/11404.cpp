#include <iostream>
#include <algorithm>
using namespace std;

#define INF 100001;
int n, m;
int graph[101][101];

void floyd(void) {
	//inter을 거쳐갈 때 비용이 더 작으면 update
	for (int inter = 1; inter <= n; inter++) {
		for (int from = 1; from <= n; from++) {
			if (!graph[from][inter]) //rfrom -> inter 가는 방법 X
				continue; //실행속도 향상
			for (int to = 1; to <= n; to++) {
				if (graph[inter][to] == 0 || from == to)
					continue;
				if (graph[from][to] == 0 || graph[from][to] > graph[from][inter] + graph[inter][to])
					graph[from][to] = graph[from][inter] + graph[inter][to];
			}
		}
	}
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;

		if (!graph[from][to]) // 경로가 없는 경우
			graph[from][to] = cost;
		else // 경로가 있는 경우 최소값 선택
			graph[from][to] = min(graph[from][to], cost);
	}

	floyd();

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << graph[i][j] << " ";
		}
		cout << "\n";
	}

}
