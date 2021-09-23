#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>

using namespace std;

int n, m;
int cnt[100][100] = { 0, };
int maze[100][100] = { 0 };
bool isVisited[100][100] = { false, };
int moveX[4] = { 1, -1, 0, 0 };  // x가 움직일동안 y는 움직이지 않고, 반대도 성립
int moveY[4] = { 0, 0, 1, -1 };
queue <pair<int, int>> q;  // 정수의 쌍을 저장할 수 있는 queue

void bfs(void);

int main(void) {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &maze[i][j]);
		}
	}
	bfs();
	cout << cnt[n - 1][m - 1];
	return 0;
}

void bfs(void) {
	q.push(make_pair(0, 0));
	cnt[0][0] = 1;  // 시작 위치도 개수 셈
	int x, y;

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		if (x == n - 1 && y == m - 1)
			return;
		for (int i = 0; i < 4; i++) {
			int nx = x + moveX[i];  // x,y 좌표를 하나만 1씩 움직임
			int ny = y + moveY[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m)  // map 밖으로 나가면 다음 반복문
				continue;
			if (maze[nx][ny] == 1 && !isVisited[nx][ny]) {  // 이동할 수 있고 방문하지 않았다면
				isVisited[nx][ny] = true; // 방문 표시
				q.push(make_pair(nx, ny));  // 인접한 좌표를 q에 push
				cnt[nx][ny] = cnt[x][y] + 1;
			}
		}
	}
}
