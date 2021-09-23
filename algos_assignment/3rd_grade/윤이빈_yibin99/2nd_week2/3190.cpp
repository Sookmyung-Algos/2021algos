#include <iostream>
#include <queue>
using namespace std;

int board[101][101];
queue<pair<int,int>> snake;
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int d=0, t=0, row=1, col=1;
bool flag=true;

void go(){
    t++;
    int nextr=row+dir[d][0];
    int nextc=col+dir[d][1];
    if(board[nextr][nextc]==-1){
        flag=false;
    }
    else if(board[nextr][nextc]==1){
        board[nextr][nextc]=-1;
        snake.push({nextr,nextc});
    }
    else{
        board[snake.front().first][snake.front().second]=0;
        snake.pop();
        board[nextr][nextc]=-1;
        snake.push({nextr,nextc});
    }
    row=nextr;
    col=nextc;
}

int main(){
    int n, k;
    cin >> n >> k;
    for(int i=0;i<k;i++){
        int r, c;
        cin >> r >> c;
        board[r][c]=1;
    }
    for(int i=0;i<=n;i++){
        board[0][i]=-1;
        board[i][0]=-1;
        board[n+1][i]=-1;
        board[i][n+1]=-1;
    }
    snake.push({0,0});
    int l;
    cin >> l;
    for(int i=0;i<l;i++){
        int x;
        char c;
        cin >> x >> c;
        while(t<x){
            go();
            if(!flag) break;
        }
        if(!flag) break;
        if(c=='D')  d=(d+1)%4;
        else{
            if(d<=0) d=3;
            else d-=1;
        }
    }
    while(flag){
        go();
    }
    cout << t;
}
