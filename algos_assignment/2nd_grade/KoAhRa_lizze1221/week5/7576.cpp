#include <iostream>
#include <queue> 
#include <stdio.h> 
#include <cstring>

#define MAX_SIZE 1001
using namespace std;

struct tomato {
	int y, x;
};

queue<tomato> q;

// 우,하,좌,상
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0 , -1 };

int n, m, result = 0;
int graph[MAX_SIZE][MAX_SIZE];

bool IsInside(int ny, int nx) {
	return (0 <= nx && 0 <= ny && nx < m && ny < n);
}

void bfs(void) {
	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		q.pop();// 큐의 현재 원소(익은 토마토(1))를 꺼내기

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			// 해당 위치의 주변을 확인

			if (IsInside(ny, nx) == 1 && graph[ny][nx] == 0) {
				graph[ny][nx] = graph[y][x] + 1;
				q.push({ ny, nx });
			} // 지도 안에 있는 것 중에서 익지 않은 토마토인 경우
		}
	}
}

int main() {
	scanf("%d %d", &m, &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &graph[i][j]);
			if (graph[i][j] == 1) { // 익은토마토는 push
				q.push({ i, j });
			}
		}
	}

	bfs();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (graph[i][j] == 0) { // 익지 않은 토마토가 있다면
				printf("-1\n");
				return 0;
			}
			if (result < graph[i][j]) {
				result = graph[i][j];
			}
		}
	}
	printf("%d\n", result - 1);
	return 0;
}
