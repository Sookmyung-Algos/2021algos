// 11404 플로이드

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define INF 1e9
int n, m;

int graph[101][101];

void floyd(void) {
	for (int inter = 1; inter <= n; inter++) {
		for (int from = 1; from <= n; from++) {
			if(!graph[from][inter]) // from -> inter 가는 방법 X
				continue; //실행속도 향상
			for (int to = 1; to <= n; to++) {
				if(graph[inter][to] == 0 || from == to)
					continue; //실행속도 향상
				if (graph[from][to] == 0 || graph[from][to] > graph[from][inter] + graph[inter][to])
					graph[from][to] = graph[from][inter] + graph[inter][to];
			}
		}
	}
}

int main() {
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
			if (i == j || graph[i][j] == INF)
				cout << 0 << " ";
			else
				cout << graph[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
