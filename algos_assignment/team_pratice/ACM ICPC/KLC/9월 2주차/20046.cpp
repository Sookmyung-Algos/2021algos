#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <tuple>
using namespace std;

int dx[4]={-1,1,0,0};
int dy[4]={0,0,1,-1};

int m,n;
int map[1001][1001];
bool visit[1001][1001];
int dist[1001][1001];

void solve(int x,int y);

int main(){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>m>>n;
    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            cin>>map[i][j];
            if (map[i][j]==-1)
                visit[i][j]=true;
        }
    }
    
    if (map[0][0]==-1 || map[m-1][n-1]==-1){
        cout<<"-1";
        return 0;
    }
    solve(0,0);
}

void solve(int x,int y){
    priority_queue <tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> q;
    memset(dist,-1,sizeof(dist));
    
    q.push(make_tuple(map[x][y],x,y));
    dist[x][y]=map[x][y];
    
    while (!q.empty()){
        int nowW=get<0>(q.top());
        int nowX=get<1>(q.top());
        int nowY=get<2>(q.top());
        q.pop();
        
        if (nowX==m-1 && nowY==n-1){
            cout<<nowW;
            return;
        }
        
        if (visit[nowX][nowY])
            continue;
        
        visit[nowX][nowY]=true;
        
        for (int i=0;i<4;i++){
            int nx=nowX+dx[i];
            int ny=nowY+dy[i];
            
            if (nx<0||ny<0||nx>=m||ny>=n)
                continue;
            
            if (!visit[nx][ny]){
                if (dist[nx][ny]==-1 || dist[nowX][nowY]+map[nx][ny]<dist[nx][ny]){
                    dist[nx][ny]=dist[nowX][nowY]+map[nx][ny];
                    q.push(make_tuple(dist[nx][ny],nx,ny));
                }
            }
            
        }
        
    }
    cout<<"-1";
    return;
    
}
