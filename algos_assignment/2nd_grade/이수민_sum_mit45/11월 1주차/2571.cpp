#include <iostream>
#include <algorithm>
using namespace std;

int board[101][101];
int ans = 0;

void pastePaper(int r, int c) {
    int i, j;
    for (i = r; i < r + 10; ++i) {
        for (j = c; j < c + 10; ++j) {
            board[i][j] = 1;
        }
    }
}

int isBlackPaper(int r, int c, int w, int h) {
    int i, j;
    for (i = r; i <= r + h; ++i) {
        for (j = c; j <= c + w; ++j) {
            if (board[i][j] != 1) // 어느 한 지점이라도 1이 아닌 경우
                return 0;
        }
    }
    return 1;
}

void check(int r, int c) {
    int w, h;

    for (w = 0; w < 100; w++) { // 가로 크기 증가
       
        if (c + w > 100 || board[r][c + w] == 0) // 범위를 벗어나거나 중간에 흰 영역인 경우
            break;
        
        for (h = 0; h < 100; h++) { // 세로 크기 증가
            if (r + h > 100 || board[r + h][c] == 0) // 범위를 벗어나거나 중간에 흰 영역인 경우
                break;
            if (isBlackPaper(r, c, w, h))
                ans = max(ans, (w + 1) * (h + 1));  
        }
    }
}
int main() {
    int N, i, j, r, c;
    cin >> N;
    for (i = 0; i < N; ++i) {
        cin >> r >> c;
        pastePaper(r, c);
    }
    for (r = 1; r <= 100; ++r) {
        for (c = 1; c <= 100; ++c) {
            if (board[r][c] == 1)
                check(r, c);
        }
    }
    cout << ans;
}
