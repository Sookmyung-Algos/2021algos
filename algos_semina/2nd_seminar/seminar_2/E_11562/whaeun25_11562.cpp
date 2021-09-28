#include<iostream>
#include<algorithm>

using namespace std;

int n, m, k;

int way[251][251];

void floyd() {
	for (int i = 1; i <= n; i++) {
		for (int t = 1; t <= n; t++) {
			for (int j = 1; j <= n; j++) {
				way[t][j] = min(way[t][j], way[t][i] + way[i][j]);
			}
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) {
				way[i][j] = 0;
				continue;
			}
			way[i][j] = 31010;
		}
	}

	for (int i = 0; i < m; i++) {
		int u, v, b;

		cin >> u >> v >> b;

		way[u][v] = 0;
		if (b == 1) {
			way[v][u] = 0;
		}
		else {
			way[v][u] = 1;
		}
	}

	floyd();

	cin >> k;

	for (int i = 0; i < k; i++) {
		int s, e;
		cin >> s >> e;
		cout << way[s][e] << "\n";
	}

}
