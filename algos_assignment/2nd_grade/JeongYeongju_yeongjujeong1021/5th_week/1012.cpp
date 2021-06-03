#include <iostream>
#include <queue>
#define MAX 50
using namespace std;

int arr[MAX][MAX];
int visit[MAX][MAX];

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

queue<pair<int, int>> q;
int m, n;

void bfs(int i, int j) {
	int x, y;
	visit[i][j] = 1;
	q.push({ i, j });
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			i = x + dx[k];
			j = y + dy[k];
			if (0 <= i && i < m && 0 <= j && j < n
				&& !visit[i][j]) {
				visit[i][j] = 1;
				q.push({ i, j });
			}
		}
	}
}

int main() {
	int t, k, x, y, cnt;
	cin >> t;

	while (t--) {
		cnt = 0;
		cin >> m >> n >> k;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				arr[i][j] = 0;
				visit[i][j] = 1;
			}
		}
		for (int i = 0; i < k; i++) {
			cin >> x >> y;
			arr[x][y] = 1;
			visit[x][y] = 0;
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[i][j] && !visit[i][j]) {
					bfs(i, j);
					cnt++;
				}
			}
		}
		cout << cnt << '\n';
	}
}
