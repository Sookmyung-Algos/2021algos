#include <iostream>

using namespace std;

int paper[128][128];
int white = 0;
int blue = 0;

bool check(int x, int y, int m) {
    int checkInt = paper[x][y];
    for (int i = x; i < x + m; i++) {
        for (int j = y; j < y + m; j++) {
            if (checkInt != paper[i][j]) return false;
        }
    }
    if (checkInt == 0) white++;
    else blue++;
    return true;
}

void solve(int x, int y, int m) {
    if (check(x, y, m)) {
        return;
    } else {
        int k = m / 2;
        solve(x, y, k);
        solve(x, y + k, k);
        solve(x + k, y, k);
        solve(x + k, y + k, k);
    }
}

int main(int argc, const char * argv[]) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &paper[i][j]);
        }
    }
    solve(0, 0, n);
    cout << white << '\n' << blue;
    return 0;
}
