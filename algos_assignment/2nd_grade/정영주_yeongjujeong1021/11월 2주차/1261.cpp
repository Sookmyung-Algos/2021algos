#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 1e9
using namespace std;

int n, m;
int arr[101][101];
int dist[101][101];

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

priority_queue<pair<int, pair<int, int>>> pq;

void dijkstra() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			dist[i][j] = INF;
	pq.push({ 0, {0, 0} });
	dist[0][0] = 0;

	while (!pq.empty()) {
		int a = pq.top().second.first;
		int b = pq.top().second.second;
		int c = -pq.top().first;
		pq.pop();

		if (dist[a][b] < c) continue;
		
		for (int k = 0; k < 4; k++) {
			int x = a + dx[k];
			int y = b + dy[k];

			if (0 <= x && x < n && 0 <= y && y < m && dist[x][y] > c + arr[x][y]) {
				dist[x][y] = c + arr[x][y];
				pq.push({ -dist[x][y], {x, y} });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> m >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c; cin >> c;
			arr[i][j] = c - '0';
		}
	}

	dijkstra();

	cout << dist[n - 1][m - 1] << '\n';

	return 0;
}
