// 1012 유기농 배추

#include <iostream>
#include <queue>
using namespace std;

int N,M;
int arr[50][50];    // 배추밭 0으로 초기화
int dx[4] = { -1, 1, 0, 0 };    // 좌,우,상,하 
int dy[4] = { 0, 0, -1, 1 };

void bfs(int x, int y) {

    queue<pair<int, int>> q;
    q.push(make_pair(x, y));    // 입력 받은 배추 위치 큐에 삽입
    arr[x][y] = 0;

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i) {   //상하좌우 탐색
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (0 <= nx && nx < M && 0 <= ny && ny < N) {
                if (arr[nx][ny] == 1) { // 현재 위치에 배추가 있다면
                    arr[nx][ny] = 0;    // 방문했음을 표시
                    q.push(make_pair(nx, ny));  // 큐에 현재 배추 위치 삽입
                }
            }
        }
    }
}

int main() {

    int num;
    int m, n;
    int cabbage;

    cin >> num;

    for (int t = 0; t < num; ++t) {
        cin >> M >> N >> cabbage;
            
        for (int i = 0; i < cabbage; ++i) {
            cin >> m >> n;
            arr[m][n] = 1;
        }   // 배추 위치

        int cnt = 0;    // 배추흰지렁이 개수   

        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (arr[i][j] == 1) {
                    bfs(i, j);
                    cnt++;
                }
            }
        }

        cout << cnt << '\n';
    }

    return 0;
}
