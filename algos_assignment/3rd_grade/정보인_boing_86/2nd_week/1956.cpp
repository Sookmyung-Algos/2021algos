#include <iostream>
#include <algorithm>

#define INF 10000000

using namespace std;

int n,m;
int graph[401][401];

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

	cin >> n >> m;

	init();

	int a, b, c;
	for (int i = 1; i <= m; i++) {
		cin >> a >> b >> c;
		graph[a][b] = c;
	}
	FW();

	int dist = INF;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) {
				continue;
			}
			else if (graph[i][j] != INF && graph[j][i] != INF) {
				dist = min(dist, graph[i][j] + graph[j][i]);
			}
		}
	}

	if (dist == INF) {
		cout << "-1\n";
	}

	else {
		cout << dist << endl;
	}

	return 0;


}
