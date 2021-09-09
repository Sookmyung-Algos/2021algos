#include <iostream>
#include <algorithm>
using namespace std;
int dx[]={-1, 1, 0, 0};
int dy[]={0, 0, -1, 1};
int board[500][500];
int ch[500][500];
int n,m,memo;
void exce(int y, int x){
    if(y+1<n && x+2<m)
        memo=max(memo, board[y][x]+board[y][x+1]+board[y][x+2]+board[y+1][x+1]);
    if(y+2<n && x+1<m)
        memo=max(memo, board[y][x]+board[y+1][x]+board[y+1][x+1]+board[y+2][x]);
    if(y-1>= 0 && x+2<m)
        memo=max(memo, board[y][x]+board[y][x+1]+board[y][x+2]+board[y-1][x+1]);
    if(y+2<n && x-1>= 0)
        memo=max(memo, board[y][x]+board[y+1][x]+board[y+1][x-1]+board[y+2][x]);
}

void find(int L, int sum, int y, int x){
    if(L==3){
        memo=max(memo, sum);
        return;
    }
    for(int i=0;i<4;i++){
    	int nx=x+dx[i];
        int ny=y+dy[i];
        if(ny<0|| nx<0 || ny>=n || nx>=m) continue;
        if(ch[ny][nx]) continue;
        ch[ny][nx] = true;
        find(L+1, sum+board[ny][nx], ny, nx);
        ch[ny][nx] = false;
    }
}
void mmax(int y, int x)
{
    exce(y, x);
    ch[y][x]=true;
    find(0, board[y][x], y, x);
    ch[y][x]=false;
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>board[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            mmax(i, j);
        }
    }
    cout<<memo<<"\n";

}
