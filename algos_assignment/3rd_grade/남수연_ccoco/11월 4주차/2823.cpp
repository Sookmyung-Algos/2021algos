#include <iostream>

using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int r, c;
char jido[13][13];


int main(int argc, const char * argv[]) {
    cin >> r >> c;
    for (int i = 1; i < r + 1; i++) {
        getchar();
        for (int j = 1; j < c + 1; j++) {
            scanf("%c", &jido[i][j]);
        }
    }
    
    for (int i = 0; i < c + 2; i++) {
        jido[0][i] = 'X';
        jido[r + 1][i] = 'X';
    }
    for (int i = 0; i < r + 2; i++) {
        jido[i][0] = 'X';
        jido[i][c + 1] = 'X';
    }
    
    for (int i = 1; i < r + 1; i++) {
        for (int j = 1; j < c + 1; j++) {
            int cnt = 0;
            for (int k = 0; k < 4; k++) {
                if (jido[i][j] == '.' && jido[i + dx[k]][j + dy[k]] == 'X') {
                    cnt++;
                    if (cnt >= 3) {
                        printf("1");
                        exit(0);
                    }
                }
            }
        }
    }
    printf("0");
    return 0;
}
