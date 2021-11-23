#include <iostream>
#include <cstdlib>
#define INF 1e9
using namespace std;

pair<int, int> pos[1001];
int dist[1001][1001];
int special[1001];

int main() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(NULL);

	int n, t; cin >> n >> t;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			dist[i][j] = INF;
		dist[i][i] = 0;
	}

	for (int i = 1, s, x, y; i <= n; i++) {
		cin >> s >> x >> y;
		pos[i] = { x, y };
		special[i] = s;
		for (int j = 1; j < i; j++) {
			if (special[i] == 1 && special[j] == 1) {
				dist[i][j] = min(dist[i][j], t);
				dist[j][i] = min(dist[j][i], t);
			}
			int d = abs(pos[i].first - pos[j].first) + abs(pos[i].second - pos[j].second);
			dist[i][j] = min(dist[i][j], d);
			dist[j][i] = min(dist[j][i], d);
		}
	}

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

	int m, a, b; cin >> m;
	while (m--) {
		cin >> a >> b;
		cout << dist[a][b] << '\n';
	}

	return 0;
}
