#include <iostream>
#include <algorithm>

#define INF 10000000

using namespace std;

int n, m;
int graph[251][251];

void FW() {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}
}

void init() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) {
				graph[i][j] = 0;
			}
			else {
				graph[i][j] = INF;
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int u, v, b;
	int k, s, e;
	cin >> n >> m;

	init();

	for (int i = 1; i <= m; i++) {
		cin >> u >> v >> b;
		if (b == 0) {
			graph[u][v] = 0;
			graph[v][u] = 1;
		}
		else {
			graph[u][v] = graph[v][u] = 0;
		}
	}

	FW();

	cin >> k;
	for (int i = 1; i <= k; i++) {
		cin >> s >> e;
		cout << graph[s][e] << "\n";
	}
	return 0;
}
