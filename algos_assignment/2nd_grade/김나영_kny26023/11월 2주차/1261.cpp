#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

#define INF 987654321

using namespace std;

int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };
int arr[101][101];
int dist[101][101];

queue<pair<int, int>> pq;

void dijkstra(int m, int n, int r, int c) {
	pq.push({ r,c });
	dist[r][c] = 0;

	while (!pq.empty()) {
		int y = pq.front().first;
		int x = pq.front().second;
		pq.pop();

		for (int i = 0; i < 4; i++) {
			int yy = y + dy[i];
			int xx = x + dx[i];

			if (yy < 0 || yy >= n || xx < 0 || xx >= m) 
                continue;
            
			if (arr[yy][xx] == 1) {
				if (dist[yy][xx] > dist[y][x] + 1) {
					dist[yy][xx] = dist[y][x] + 1;
					pq.push({ yy,xx });
				}
			}
			else if (arr[yy][xx] == 0) {
				if (dist[yy][xx] > dist[y][x]) {
					dist[yy][xx] = dist[y][x];
					pq.push({ yy,xx });
				}
			}
		}
	}
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int m, n;
	scanf("%d %d", &m, &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &arr[i][j]);
			dist[i][j] = INF;
		}
	}

	dijkstra(m, n, 0, 0);
	printf("%d", dist[n - 1][m - 1]);
	return 0;
}
