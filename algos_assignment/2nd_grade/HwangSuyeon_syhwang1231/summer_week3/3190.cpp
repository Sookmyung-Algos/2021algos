// 3190: 뱀 (Gold 5)
#include <iostream>
#include <deque>
#define MAX 101
using namespace std;

int N, K, L;
bool snake[MAX][MAX];
bool apple[MAX][MAX];
pair<int, int> dir[] = { {0,1}, {1,0}, {0,-1}, {-1,0} };  // 우,하,좌,상(first:행, second:열)
deque<pair<int, char>> sDir;
deque<pair<int, int>> snakeLoc;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    cin >> K;
    for (int i = 0; i < K; i++) {
        int r, c;
        cin >> r >> c;
        apple[r][c] = true;
    }
    cin >> L;
    for (int i = 0; i < L; i++) {
        int x;
        char c;
        cin >> x >> c;
        sDir.push_back({ x,c });
    }

    int cnt = 0;  // 초 세기
    int row = 1;  // 행
    int col = 1;  // 열
    int dirIndex = 0;  // 초기 움직이는 방향은 오른쪽
    snakeLoc.push_back({ 1,1 });
    snake[row][col] = true;

    while (true) {
        if (!sDir.empty() && sDir.front().first == cnt) {  // 방향을 바꿀 차례라면 방향 바꾸기
            char c = sDir.front().second;
            if (c == 'L') {
                dirIndex--;
                if (dirIndex < 0)
                    dirIndex = 3;
            }
            else if (c == 'D') {
                dirIndex++;
                if (dirIndex > 3)
                    dirIndex = 0;
            }
            sDir.pop_front();
        }

        auto p = dir[dirIndex];
        int newRow = row + p.first;
        int newCol = col + p.second;

        // 종결조건
        if (newRow <= 0 || newRow > N || newCol <= 0 || newCol > N || snake[newRow][newCol])  // 벽 혹은 자기자신
            break;

        if (!apple[newRow][newCol]) {  // 다음 칸에 사과 없는 경우에는 꼬리 위치 빼기
            snake[snakeLoc.front().first][snakeLoc.front().second] = false;
            snakeLoc.pop_front();
        }
        else  // 다음 칸에 사과 있는 경우 먹고 없애기
            apple[newRow][newCol] = false;
        snakeLoc.push_back({ newRow,newCol });  // 이동한 위치 push back, snake배열에 true 저장
        snake[newRow][newCol] = true;

        row = newRow;
        col = newCol;
        cnt++;
    }
    cout << cnt+1;
    return 0;
}
