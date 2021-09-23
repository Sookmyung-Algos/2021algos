#include <iostream>
using namespace std;
 
int m, n, k;
void dfs(int,int);

int map[50][50] = { 0, };
int direct[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
 
int main(void){
    int t;
    cin >> t;
 
    for (int i = 0; i < t; i++) {
 
        int result = 0;
        cin >> m >> n >> k;
 
        for (int j = 0; j < k; j++) {
            int x, y;
            cin >> x >> y;
            map[y][x] = 1;
        }
 
        for (int col = 0; col < m; col++) {
            for (int row = 0; row < n; row++) {
                if (map[row][col] == 1) {
                    dfs(row, col);
                    result++;
                }
            }
        }
 
        cout << result << endl;
    }
}
 
void dfs(int row, int col) {
    map[row][col] = 0;
 
    for (int i = 0; i < 4; i++) {
        int next[2] = { row + direct[i][0], col + direct[i][1] };
        bool possible = (next[0] >= 0 && next[0] < n && next[1] >= 0 && next[1] < m) && map[next[0]][next[1]] == 1;
 
        if (possible)
            dfs(next[0], next[1]);
    }
}
