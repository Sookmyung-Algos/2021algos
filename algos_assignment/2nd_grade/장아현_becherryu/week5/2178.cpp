//최소 칸수 bfs이용
#include <iostream>
#include <queue>
using namespace std;

int dist[101][101];
int arr[101][101];
int n, m;
queue<pair<int, int>> q;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void bfs(int x, int y) {
	q.push(make_pair(x, y));
	dist[x][y] = true;
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx <= 0 || ny <= 0 || nx > n || ny > m) continue;
			if (dist[nx][ny] == 0 && arr[nx][ny] == 1) {
				dist[nx][ny] = dist[x][y] + 1;
				q.push(make_pair(nx, ny));
			}
		}
	}
}

int main(int argc, const char* argv[]) {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%1d", &arr[i][j]);

	bfs(1, 1);
	cout << dist[n][m] << "\n";

}
