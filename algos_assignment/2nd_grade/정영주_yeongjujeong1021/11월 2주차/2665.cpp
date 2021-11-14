#include <iostream>
#include <queue>
#define INF 1e9
using namespace std;

int n;
int arr[51][51];
int dist[51][51];

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void dijkstra() {
	priority_queue<pair<int, pair<int, int>>> pq;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) dist[i][j] = INF;
	dist[0][0] = 0;
	pq.push({ 0, { 0, 0 } });

	while (!pq.empty()) {
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		int z = pq.top().first;
		pq.pop();

		if (dist[x][y] > z) continue;

		for (int k = 0; k < 4; k++) {
			int a = x + dx[k];
			int b = y + dy[k];
			
			if (a < 0 || n <= a || b < 0 || n <= b) continue;

			int c = z + arr[a][b];
			if (dist[a][b] > c) {
				dist[a][b] = c;
				pq.push({ c, {a, b} });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char c; cin >> c;
			if (c == '0') arr[i][j] = 1;
		}
	}

	dijkstra();

	cout << dist[n - 1][n - 1] << '\n';

	return 0;
}
