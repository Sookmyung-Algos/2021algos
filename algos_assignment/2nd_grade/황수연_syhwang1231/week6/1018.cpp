// 1018: 체스판 다시 칠하기 (Silver 5)
#include <iostream>
#include <algorithm>
#define MAX 50
using namespace std;

int M, N;  //M:가로, N:세로
string board[MAX];
string black[8]{
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB"
};

string white[8] = {
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW"
};

int whiteFirst(int r, int c) {
    int cnt = 0;
    for (int i = r; i < r + 8; i++) {
        for (int j = c; j < c + 8; j++) {
            if (board[i][j] != white[i - r][j - c])
                cnt++;
        }
    }
    return cnt;
}

int blackFirst(int r, int c) {
    int cnt = 0;
    for (int i = r; i < r + 8; i++) {
        for (int j = c; j < c + 8; j++) {
            if (board[i][j] != black[i - r][j - c])
                cnt++;
        }
    }
    return cnt;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int result = 2501;
    cin >> M >> N;
    for (int i = 0; i < M; i++)
        cin >> board[i];

    for (int i = 0; i + 7 < M; i++) {
        for (int j = 0; j + 7 < N; j++) {
            result = min(min(result, whiteFirst(i, j)), blackFirst(i, j));
        }
    }
    cout << result;
    return 0;
}
