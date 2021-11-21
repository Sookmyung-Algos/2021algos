#include <iostream>
#define INF 1e9
using namespace std;

pair<int, int> p[101];
int dist[101][101];

int main() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(NULL);

	int t, n, x, y;
	pair<int, int> st, en;
	cin >> t;

	while (t--) {
		cin >> n;
		for (int i = 0; i < n + 2; i++) {
			for (int j = 0; j < n + 2; j++)
				dist[i][j] = INF;
			dist[i][i] = 0;
		}

		for (int i = 0; i < n + 2; i++) {
			cin >> x >> y;
			p[i] = { x, y };
			for (int j = 0; j < i; j++) {
				int d = abs(p[i].first - p[j].first) + abs(p[i].second - p[j].second);
				if (d <= 1000) {
					dist[i][j] = min(dist[i][j], d);
					dist[j][i] = min(dist[j][i], d);
				}
					
			}
		}

		for (int k = 0; k < n + 2; k++)
			for (int i = 0; i < n + 2; i++)
				for (int j = 0; j < n + 2; j++)
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

		if (dist[0][n + 1] == INF) cout << "sad\n";
		else cout << "happy\n";
	}

	return 0;
}
