#include <iostream>
using namespace std;

bool alpha[27] = {false, };
char board[21][21];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int r, c;
int max_cnt=0;

void dfs(int x, int y, int cnt){
    if(cnt>max_cnt) max_cnt=cnt;
    for(int i=0; i<4; i++){
        int next_x = x+dx[i];
        int next_y = y+dy[i];
        if(next_x>0 && next_x<=r && next_y>0 && next_y<=c && !alpha[board[next_x][next_y]-'A']){
            alpha[board[next_x][next_y] - 'A'] = true;
            dfs(next_x, next_y, cnt+1);
            alpha[board[next_x][next_y]-'A'] = false;
        }
    }
}

int main(){
    cin >> r >> c;
    for(int i=1; i<=r; i++)
        for(int j=0; j<=c; j++)
            scanf("%c", &board[i][j]);
    alpha[board[1][1] - 'A'] = true;
    dfs(1, 1, 1);
    cout << max_cnt;
}
