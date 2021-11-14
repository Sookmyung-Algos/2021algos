#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 1001
#define INF 1e9

int n, m; 
int dodo_x, dodo_y, exit_x, exit_y;
int dist[MAX][MAX];
int mapp[MAX][MAX];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void dijkstra() {
	priority_queue <pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

	pq.push({ 0, {dodo_x, dodo_y} });
	dist[dodo_y][dodo_x] = 0;

	while (!pq.empty()) {
		int hp = pq.top().first;
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		pq.pop();

		if (x == exit_x && y == exit_y) return;

		if (dist[y][x] > hp) continue;

		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];

			if (xx >= m || yy >= n || xx < 0 || yy < 0) continue;

			if (dy[i] == -1) { // 사다리 타고 올라가는 경우
				if (mapp[y][x] == 'L') {
					if (mapp[yy][xx] == 'X' || mapp[yy][xx] == 'D') continue;
					if (dist[yy][xx] > hp + 5) {
						dist[yy][xx] = hp + 5;
						pq.push({ hp + 5, { xx, yy } });
					}
				}
			}
			else if (dy[i] == 1) { // 사다리 타고 내려가는 경우
				if (mapp[yy][xx] == 'L') {
					if (dist[yy][xx] > hp + 5) {
						dist[yy][xx] = hp + 5;
						pq.push({ hp + 5, {xx,yy} });
					}
				}
			}
			else if (dx[i] == 1 || dx[i] == -1) {
				if (mapp[yy][xx] == 'X') { // 빈 공간이 있는 경우
					while (mapp[yy][xx] == 'X') yy++;
					if (mapp[yy][xx] == 'D') continue;
					if (dist[yy][xx] > hp + 11) {
						dist[yy][xx] = hp + 11;
						pq.push({ hp + 11, {xx, yy} });
					}
				}
				else if (mapp[yy][xx] == 'L' || mapp[yy][xx] == 'F' || mapp[yy][xx] == 'E') {
					if (dist[yy][xx] > hp + 1) {
						dist[yy][xx] = hp + 1;
						pq.push({ hp + 1, {xx, yy} });
					}
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c; cin >> c;
			mapp[i][j] = c;
			if (mapp[i][j] == 'C') dodo_y = i, dodo_x = j;
			else if (mapp[i][j] == 'E') exit_y = i, exit_x = j;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dist[i][j] = INF;
		}
	}

	dijkstra();

	if (dist[exit_y][exit_x] != INF) cout << dist[exit_y][exit_x];
	else cout << "dodo sad";
}
