#include <iostream>
#include <cstring>
using namespace std;

int N;
int arr[100][100];
int visit[100][100]; // 0으로 초기화

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

//각 color에 대해 탐색
int dfs(int color, int x, int y) {
    visit[x][y] = 1; // 방문하면 1로 수정

    for (int i = 0; i < 4; i++) {

        int movex, movey;
        movex= x + dx[i]; // x기준 상하좌우 
        movey = y + dy[i]; // y기준 상하좌우

        if (movex >= 0 && movey >= 0 && movex < N && movey < N && arr[movex][movey] == color && !visit[movex][movey]) {
            dfs(color, movex, movey);
        }
    }
    return 0;
}

//Red-Green 영역
int RedGreen(int x, int y) {
    visit[x][y] = 1;

    for (int i = 0; i < 4; i++) {
        int movex, movey;
        movex = x + dx[i]; // x기준 상하좌우 
        movey = y + dy[i]; // y기준 상하좌우

        if (movex >= 0 && movey >= 0 && movex < N && movey < N && (arr[movex][movey] == 1 || arr[movex][movey] == 2) && !visit[movex][movey]) {
            RedGreen(movex, movey);
        }
    }
    return 0;
}


int main() {
    cin >> N;

    char color[101];

    for (int i = 0; i < N; i++) {
        cin >> color;

        // 숫자로 바꿔서 저장
        for (int j = 0; j < N; j++) {
            if (color[j] == 'R') arr[i][j] = 1;
            else if (color[j] == 'G') arr[i][j] = 2;
            else arr[i][j] = 3;
        }
    }

    int red = 0, green = 0, blue = 0, red_green = 0;

    //빨초파 영역 개수 구하기
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (arr[i][j] == 1 && !visit[i][j]) { 
                dfs(1, i, j);
                red++;
            }
            if (arr[i][j] == 2 && !visit[i][j]) {
                dfs(2, i, j);
                green++;
            }
            if (arr[i][j] == 3 && !visit[i][j]) {
                dfs(3, i, j);
                blue++;
            }
        }
    }

    //방문기록 초기화하고 빨-초 영역 구하기
    memset(visit, 0, sizeof(visit));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if ((arr[i][j] == 1 || arr[i][j] == 2) && !visit[i][j]) {
                RedGreen(i, j);
                red_green++;
            }
        }
    }

    //결과 
    int result1 = red + green + blue;
    int result2 = red_green + blue;
    printf("%d %d\n", result1, result2);
    return 0;
}
