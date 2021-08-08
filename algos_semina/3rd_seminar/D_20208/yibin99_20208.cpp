#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

int n, m, h;
int sx, sy;
int visit[11][11];
vector<pair<int,int>> mint;
int ans;

void dfs(int x, int y, int cnt){
    if(abs(sx-x)+abs(sy-y)<=visit[x][y]){
        ans=(ans>cnt)?ans:cnt;
    }
    if(visit[x][y]==0)
        return;
    for(int i=0;i<mint.size();i++){
        int nx=mint[i].first;
        int ny=mint[i].second;
        int d=abs(x-nx)+abs(y-ny);
        if(visit[nx][ny]==-1){
            if(visit[x][y]>=d){
                visit[nx][ny]=visit[x][y]-d+h;
                dfs(nx, ny, cnt+1);
                visit[nx][ny]=-1;
            }
        }
    }
    
}

int main(){
    scanf("%d %d %d", &n, &m, &h);
    int tmp;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d", &tmp);
            if(tmp==1)
                sx=i, sy=j;
            if(tmp==2)
                mint.push_back({i, j});
            visit[i][j]=-1;
        }
    }
    visit[sx][sy]=m;
    dfs(sx,sy,0);
    printf("%d", ans);
}
