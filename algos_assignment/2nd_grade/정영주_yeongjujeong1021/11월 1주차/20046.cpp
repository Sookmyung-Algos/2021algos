#include <iostream>
#include <queue>
#define INF 1e9
using namespace std;

int city[1001][1001];
int dist[1001][1001];

int m, n;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

priority_queue<pair<int, pair<int, int>>> pq;

void dijkstra() {
	for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) dist[i][j] = INF;
	dist[0][0] = city[0][0];
	pq.push({ -city[0][0], {0, 0} });

	while (!pq.empty()) {
		int a = pq.top().second.first;
		int b = pq.top().second.second;
		int c = -pq.top().first;
		pq.pop();

		if (c > dist[a][b]) continue;

		for (int k = 0; k < 4; k++) {
			int na = a + dx[k];
			int nb = b + dy[k];
			int nc = c + city[na][nb];
			if (0 <= na && na < m && 0 <= nb && nb < n && city[na][nb] != -1 && dist[na][nb] > nc) {
				dist[na][nb] = nc;
				pq.push({ -nc, {na, nb} });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> m >> n;
	
	for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) cin >> city[i][j];

	if (city[0][0] != -1 && city[m - 1][n - 1] != -1) {
		dijkstra();
		if (dist[m - 1][n - 1] == INF) cout << "-1\n";
		else cout << dist[m - 1][n - 1] << '\n';
	}
	else cout << "-1\n";

	return 0;
}
