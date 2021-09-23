#include <iostream>
#include <cstring>
using namespace std;

bool baechu[51][51];
bool visit[51][51];
int m, n, k, t, cnt = 0;
int mv_x[4] = { -1,1,0,0 };
int mv_y[4] = { 0,0,-1,1 };

void dfs(int x, int y);

int main() {
	cin >> t;

	while (t--) {
		cin >> m >> n >> k;
		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> x >> y;
			baechu[y][x] = 1;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!visit[i][j] && baechu[i][j]) {
					dfs(i, j);
					cnt++;
				}
			}
		}

		cout << cnt << "\n";
		cnt = 0;
		memset(visit, false, sizeof(visit));
		memset(baechu, false, sizeof(baechu));
	}
}

void dfs(int x, int y) {
	visit[x][y] = 1;

	for (int i = 0; i < 4; i++) { // 상하좌우 배추 탐색
		int nextX = x + mv_x[i];
		int nextY = y + mv_y[i];

		if (!visit[nextX][nextY] && baechu[nextX][nextY] == 1 && nextX >= 0 && nextX < n && nextY >= 0 && nextY < m) {
			dfs(nextX, nextY);
		}
	}
}
