#include <iostream>
#include <queue>
#include <cstring>
#define MAX 1001
using namespace std;

/*
    1. map은 빌딩의 구조를 저장하는 배열
    2. person[i][j] = 이 곳에 도착할 때까지 걸린 시간
    3. 모든 불의 위치를 돌면서 1초 뒤에 번지는 곳까지 불이 나는 것을 저장 -> bfs
    4. 3에서 불의 위치를 갱신했으므로 이후에 사람이 동서남북으로 움직일 때 갈 수 있는 곳 확인 -> bfs
    5. 갈 수 있으면 person배열에서 그 좌표의 값을 이전의 값+1 한 값으로 저장
    6. 이 모든 과정은 personQ가 empty 하지 않을 동안 진행
    7. 사람의 이동에서 현재 위치가 가장자리이면 탈출 가능, 이외의 경우, 즉 while문 빠져나오면 탈출 불가
*/

int t, w, h;
char map[MAX][MAX];  // 빌딩
int person[MAX][MAX];  // 해당 좌표에 도착할 때 걸린 시간(초) 저장
queue<pair<int, int>> fireQ;  // 불
queue<pair<int, int>> personQ;  // 사람
bool visited[MAX][MAX];  // 사람이 방문했는지 여부
int dirR[] = { 1, -1, 0, 0 };
int dirC[] = { 0, 0, 1, -1 };

void solution() {  // 불에 대한 bfs, 사람에 대한 bfs로 총 bfs 두 번 진행
    while (!personQ.empty()) {
        // 불 먼저 이동
        int fireSize = fireQ.size();

        for (int i = 0; i < fireSize; i++) {
            auto cur = fireQ.front();
            fireQ.pop();

            for (int j = 0; j < 4; j++) {
                int newR = cur.first + dirR[j];
                int newC = cur.second + dirC[j];

                if (newR < 0 || newR >= h || newC < 0 || newC >= w)  // 범위 유효 확인 -> = 안 써서 틀렸습니다 나옴
                    continue;
                if (map[newR][newC] == '#'  || map[newR][newC] == '*')  // 벽이거나 이미 불이 있는 경우 pass
                    continue;
                map[newR][newC] = '*';  // 새로 불이 번지는 위치에 *(불) 표시
                fireQ.push({ newR, newC });  // 새 좌표를 큐에 push
            }
        }

        int personSize = personQ.size();

        for (int i = 0; i < personSize; i++) {
            auto cur = personQ.front();
            personQ.pop();

            for (int j = 0; j < 4; j++) {
                int newR = cur.first + dirR[j];
                int newC = cur.second + dirC[j];


                if (map[newR][newC] == '#' || map[newR][newC] == '*' || visited[newR][newC])  // 벽, 불 혹은 이미 방문한 경우
                    continue;

                if (newR < 0 || newR > h - 1 || newC < 0 || newC > w - 1) {  // 가장자리 도착하면 탈출
                    cout << person[cur.first][cur.second] + 1 << "\n";
                    return;
                }

                person[newR][newC] = person[cur.first][cur.second] + 1;
                personQ.push({ newR, newC });
                visited[newR][newC] = true;
            }
        }
    }
    cout << "IMPOSSIBLE\n";
    return;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> t;  // 테스트 케이스 개수

    while (t--) {
        memset(map, 0, sizeof(map));
        memset(person, 0, sizeof(person));
        memset(visited, false, sizeof(visited));
        char c;

        cin >> w >> h;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> c;
                map[i][j] = c;
                if (c == '*')
                    fireQ.push({ i,j });
                if (c == '@') {
                    personQ.push({ i,j });
                    visited[i][j] = true;
                }
            }
        }
        solution();
        while(!personQ.empty())
            personQ.pop();
        while (!fireQ.empty())
            fireQ.pop();
    }
    return 0;
}
