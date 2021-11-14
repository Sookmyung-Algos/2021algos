// 2665(Gold 4) - 미로 만들기
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 50
#define INF 1e9

using namespace std;

int n;
int map[MAX][MAX];
int cost[MAX][MAX];  // 결과적으로 cost[n-1][n-1]에 저장되는 값이 바꿔야할 최소의 검은 방 수
int dx[] = { -1, 1, 0, 0 };  // 좌, 우, 상, 하
int dy[] = { 0, 0, -1, 1 };
priority_queue < pair<int, pair<int, int>>> pq;  // first: 거리, second: {x,y}(위치)

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d", &n);
    fill(&cost[0][0], &cost[n - 1][n - 1], INF);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%1d", &map[i][j]);
            map[i][j] = (map[i][j] == 0) ? 1 : 0;  // 0이면 검은 방이므로 가중치를 위해 1로 다시 저장한다
        }
    }

    cost[0][0] = 0;
    pq.push({ 0, { 0, 0 } });

    while (!pq.empty()) {
        int cnt = -pq.top().first;
        int curX = pq.top().second.first;
        int curY = pq.top().second.second;

        pq.pop();

        if (cost[curX][curY] < cnt)  // 갱신할 필요 없는 경우
            continue;

        for (int i = 0; i < 4; i++) {  // 현재 위치에서 상하좌우 탐색
            int nX = curX + dx[i];
            int nY = curY + dy[i];

            if (nX < 0 || nX >= n || nY < 0 || nY >= n)  // 배열 map의 범위 벗어나는지 확인
                continue;

            // 다음 위치의  nextCnt 값 갱신
            int nextCnt = cnt + map[nX][nY];

            if (cost[nX][nY] > nextCnt) {
                cost[nX][nY] = nextCnt;
                pq.push({ -nextCnt, {nX, nY} });
            }
        }
    }

    printf("%d", (cost[n - 2][n - 1] > cost[n - 1][n - 2]) ? cost[n - 1][n - 2] : cost[n - 2][n - 1]);
    return 0;
}
