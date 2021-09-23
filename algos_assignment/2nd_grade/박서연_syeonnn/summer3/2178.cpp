// 2178 미로 탐색

#include <iostream>
#include <queue>
using namespace std;

int N, M;
int map[100][100];
bool visited[100][100];
int cnt[100][100];

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void bfs() {
	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));

	visited[0][0] = true;
	cnt[0][0]++;

	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < M && !visited[nx][ny] && map[nx][ny] == 1) {
				visited[nx][ny] = true;
				q.push({ nx, ny });
				cnt[nx][ny] = cnt[cx][cy] + 1;
			}
		}
	}
}
int main(void) {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	bfs();

	cout << cnt[N - 1][M - 1];

	return 0;
}
