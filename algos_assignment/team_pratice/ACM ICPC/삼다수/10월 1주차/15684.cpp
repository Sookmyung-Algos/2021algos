#include <iostream>
#include <string.h>
using namespace std;

int ans = -1;
int N, M, H;
int ladder[12][32] = { 0 };
int line_cnt = 0; //추가할 가로선의 개수

int line_check(int y, int x) {

    for (int j = x;j <= H;j++) {
        if (ladder[y][j])    return line_check(y + 1, j + 1);
        if (ladder[y - 1][j])  return line_check(y - 1, j + 1);
    }

    return y;
}

//i번째의 세로선의 결과가 i번인지 확인
bool solve() {
    for (int y = 1;y <= N;y++) {
        if (line_check(y, 1) != y) {
            return false;
        }
    }
    return true;
}

void dfs_connect(int y, int cnt) {

    if (cnt > 3 || ans != -1)
        return;

    if (line_cnt == cnt) {
        if (solve()) {
            ans = cnt;
        }
         return;
    }

    for (;y < N;y++) {
        for (int x = 1;x <= H;x++) {
            //오른쪽 긋기
            if (ladder[y][x] == 0) {
                if (y == N - 1 || (ladder[y + 1][x] == 0 && ladder[y - 1][x] == 0)) {
                    ladder[y][x]++;
                    dfs_connect(y, cnt + 1);
                    ladder[y][x]--;
                }
            }
        }

    }
}

int main() {

    cin >> N >> M >> H;

    if (M == 0) {
        cout << 0 << endl;
        return 0;
    }

    int a, b;
    for (int i = 0;i < M;i++) {
        scanf("%d %d", &a, &b);
        ladder[b][a] = 1; //b,b+1세로선과 a가로선
    }

    for (int i = 0; i < 4; i++) {
        line_cnt = i;
        dfs_connect(1, 0);

        if (ans != -1)
            break;
    }
    cout << ans << endl;

    return 0;
}
