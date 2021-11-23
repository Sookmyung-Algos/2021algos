#include <iostream>
#define INF 1e9
using namespace std;

int dist[501][501];

int main() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			dist[i][j] = INF;
		dist[i][i] = 0;
	}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> dist[i][j];

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

	for (int i = 0, a, b, c; i < m; i++) {
		cin >> a >> b >> c;
		if (dist[a][b] <= c) cout << "Enjoy other party\n";
		else cout << "Stay here\n";
	}

	return 0;
}
