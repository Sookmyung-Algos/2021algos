#include <iostream>
#include <queue>
#define MAX 51

using namespace std;

int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[8] = { 0, -1, 1, -1, 1, 0, -1, 1 };

int map[MAX][MAX];
int visit[MAX][MAX];

queue<pair<int, int>> q;

void bfs(int i, int j) {
	int a, b, x, y;

	q.push({ i, j });
	visit[i][j] = 1;

	while (!q.empty()) {
		a = q.front().first;
		b = q.front().second;
		q.pop();

		for (int k = 0; k < 8; k++) {
			x = a + dx[k];
			y = b + dy[k];
			if (map[x][y] && !visit[x][y]) {
				visit[x][y] = 1;
				q.push({ x, y });
			}
		}
	}
}

int main() {
	int w, h, cnt;
	while (1) {
		cin >> w >> h;
		if (!w && !h) break;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map[i][j];
				visit[i][j] = 0;
			}
		}
		cnt = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (map[i][j] && !visit[i][j]) {
					bfs(i, j);
					cnt++;
				}
			}
		}
		cout << cnt << '\n';
	}
}
