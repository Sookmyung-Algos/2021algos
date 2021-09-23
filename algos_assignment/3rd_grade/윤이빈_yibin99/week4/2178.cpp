#include <cstdio>
#include <queue>
using namespace std;

int n, m;
int miro[101][101];
int vis[101][101]={0, };
int dx[4]={1, 0, -1, 0};
int dy[4]={0, 1, 0, -1};
queue<pair<int,int>> q;

void bfs(){
    int x, y, nx, ny;
    while(!q.empty()){
        x=q.front().first, y=q.front().second;
        q.pop();
        if(x==n && y==m) return;
        for(int i=0;i<4;i++){
            nx=x+dx[i], ny=y+dy[i];
            if(nx>0 && nx<=n && ny>0 && ny<=m && miro[nx][ny]==1 && vis[nx][ny]==0)
                q.push(make_pair(nx,ny)); vis[nx][ny]=vis[x][y]+1;
        }
    }
}

int main(){    
    scanf("%d %d", &n, &m);
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++)
            scanf("%1d", &miro[i][j]);
    }
    q.push(make_pair(1,1));
    vis[1][1]=1;
    bfs();
    printf("%d", vis[n][m]);
}
