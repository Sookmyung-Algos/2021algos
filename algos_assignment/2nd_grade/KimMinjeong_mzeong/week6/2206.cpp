#include <iostream>
#include <queue>
#include <string.h> // memset
#include <algorithm>
using namespace std;

int n, m;
int MAP[1001][1001];
int dist[1001][1001][2];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void bfs(int sy, int sx) {
	queue<pair<pair<int, int>, int>> q;
	memset(dist, -1, sizeof(dist));

	dist[sy][sx][0] = 1;
	q.push({ {sy, sx}, 0 });
	while (!q.empty()) {
		int y = q.front().first.first;
		int x = q.front().first.second; 
		int bk = q.front().second; q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny <= 0 || ny > n || nx <= 0 || nx > m) continue;
			
			if (MAP[ny][nx]) { // 벽o
				if (bk) continue;
				if (dist[ny][nx][1] != -1 && dist[ny][nx][1] <= dist[y][x][0] + 1) continue;
				dist[ny][nx][1] = dist[y][x][0] + 1;
				q.push({ { ny, nx }, 1 });
			}
			else { // 벽x
				if (dist[ny][nx][bk] != -1 && dist[ny][nx][bk] <= dist[y][x][bk] + 1) continue;
				dist[ny][nx][bk] = dist[y][x][bk] + 1;
				q.push({ { ny, nx }, bk });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			char input; cin >> input;
			MAP[i][j] = input - '0';
		}
	}
	bfs(1, 1);

	if (dist[n][m][0] == -1 && dist[n][m][1] == -1) cout << -1;
	else if (dist[n][m][0] != -1 && dist[n][m][1] != -1) cout << min(dist[n][m][0], dist[n][m][1]);
	else cout << max(dist[n][m][0], dist[n][m][1]);
}
