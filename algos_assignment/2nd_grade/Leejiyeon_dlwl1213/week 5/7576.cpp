#include <iostream>
#include <queue> 
#include <cstring> 
#include <stdio.h> 

#define MAX_SIZE 1000 + 1

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

/*
 BFS 알고리즘으로 탐색 진행 
 -> 익은 토마토(1)의 상하좌우의 4방향을 탐색 
 -> 각각의 상태가 토마토 창고의 크기를 안벗어나면서 안익은 상태(0)라는 조건에 해당되면 탐색한 칸 = 이미 익은토마토(1) + 1 (이미 익은 토마토는 1이고 날짜가 하루 지나면 1+1 ```
 */

void bfs(void) {
    while (!q.empty()) {
        // 큐의 현재 원소(익은 토마토(1))를 꺼내기
        int y = q.front().y;
        int x = q.front().x;
        q.pop();

        // 해당 위치의 주변을 확인
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            // 지도를 벗어나지 않고, 익지않은 토마토(0)라면
            if (IsInside(ny,nx) == 1 && graph[ny][nx] == 0) {
                graph[ny][nx] = graph[y][x] + 1;
                q.push({ ny, nx });
            }
        }
    }
}

int main() {
    // 토마토 농장(그래프)의 크기 입력 (가로/세로)
    scanf("%d %d", &m, &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == 1) {    // 익은토마토(1) -> 큐에 push
                q.push({ i, j });
            }
        }
    }

    bfs(); //bfs로 그래프 탐색

    for (int i = 0; i < n; i++) {  //날짜 계산 및 출력 
        for (int j = 0; j < m; j++) {

            if (graph[i][j] == 0) {  // 익지않은 토마토(0)의 경우
                printf("-1\n");
                return 0;
            }

            if (result < graph[i][j]) {  // 토마토가 얼마만에 익었는지?
                result = graph[i][j];
            }
        }
    }
    printf("%d\n", result-1);

    return 0;
}
