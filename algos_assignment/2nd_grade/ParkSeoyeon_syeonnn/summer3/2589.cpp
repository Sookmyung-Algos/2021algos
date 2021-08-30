// 2589 보물섬

#include <iostream>
#include <queue>
#include<algorithm>
#include<cstring>
using namespace std;

int N, M;
int map[51][51];
bool visited[51][51];
int sum[51][51];
int ans = 0;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void bfs(int x,int y) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));

	visited[x][y] = true;

	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (map[nx][ny] == 1 && !visited[nx][ny]) {
				visited[nx][ny] = true;
				q.push(make_pair(nx, ny));
				sum[nx][ny] = sum[cx][cy] + 1;
				ans = max(ans, sum[nx][ny]);	// 보물 위치 간의 최단 거리 중 최대
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;

	char lw;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> lw;
			if (lw == 'L')
				map[i][j] = 1;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 1) {
				bfs(i,j);
				memset(visited, false, sizeof(visited));
				memset(sum, 0, sizeof(sum));
			}	// 기존 문제와 달리 bfs를 반복 실행하며 이동시간이 긴 육지 두 곳을 찾아야 함. memset 필요.
		}
	}

	cout << ans;
	return 0;
}
