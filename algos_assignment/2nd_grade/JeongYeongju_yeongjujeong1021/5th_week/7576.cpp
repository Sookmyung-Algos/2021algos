#include <iostream>
#include <queue>
#define MAX 1001
using namespace std;

int box[MAX][MAX];
int visit[MAX][MAX];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

queue<pair<int, int>> q;

void bfs(int m, int n) {
	int a, b, x, y;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (box[i][j] == 1) {
				visit[i][j] = 1;
				q.push({ i, j });
			}
		}
	}

	while (!q.empty()) {
		a = q.front().first;
		b = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			x = a + dx[i];
			y = b + dy[i];
			if (0 <= x && x < n && 0 <= y && y < m
				&& !box[x][y] && !visit[x][y]) {
				visit[x][y] = visit[a][b] + 1;
				q.push({ x, y });
			}
		}
	}
}

int main() {
	int n, m, max = 1;
	cin >> m >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> box[i][j];
			visit[i][j] = 0;
		}
	}

	bfs(m, n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!box[i][j] && !visit[i][j])
				max = 0;
		}
	}

	if (max) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				if (max < visit[i][j])
					max = visit[i][j];
		}
	}

	cout << max - 1 << '\n';
}
