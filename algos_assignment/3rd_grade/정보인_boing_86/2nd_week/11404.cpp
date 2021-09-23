#include <iostream>
#include <algorithm>

#define INF 10000000

using namespace std;

int n;
int graph[101][101];

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
	int m;
	int a, b, c;
	cin >> n >> m;

	init();

	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		if (graph[a][b] > c) {
			graph[a][b] = c;
		}
	}

	FW();

	for (int a = 1; a <= n; a++) {
		for (int b = 1; b <= n; b++) {
			if (graph[a][b] == INF) {
				cout << 0 << " ";
			}
			else
				cout << graph[a][b] << " ";
		}
		cout << "\n";
	}


}
