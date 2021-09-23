#include<iostream>
#include<queue>

using namespace std;

int dx[4] = { 1,-1, 0, 0 };
int dy[4] = { 0,0, -1, 1 };
queue<pair<int, int>>q;
int m, n;
int arr[1001][1001];
int time[1001][1001] = { 0, };

void bfs() {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < n&&ny >= 0 && ny < m && (arr[nx][ny] == 0)) {
				arr[nx][ny] = 1;
				q.push({ nx,ny });
				time[nx][ny] = time[x][y]+1;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL), cout.tie(NULL);

	cin >> m >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1)
				q.push({ i,j });
		}
	}

	bfs();
	int max = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0) {
				cout << -1;
				return 0;
			}
			if (max < time[i][j])
				max = time[i][j];
		}
	}

	cout << max;
}
