//범위가 작음: 다 탐색하는 것이기 때문에
#include <iostream>
using namespace std;

int dx[4]={-1,1,0,0};
int dy[4]={0,0,1,-1};
int r,c,k;
int visit[5][5];
int cnt,result=0;

void dfs(int x,int y,int cnt){
    if (x==0 && y==c-1){
        if (cnt==k)
            result++;
        return;
    }
    
    if (!visit[x][y])
        visit[x][y]=true;
    
    for (int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        
        if (nx<0||ny<0||nx>=r||ny>=c)
            continue;
        
        if (!visit[nx][ny]){
            visit[nx][ny]=true;
            dfs(nx,ny,cnt+1);
            visit[nx][ny]=false;
        }
    }
}

int main(){
    char x;
    
    cin>>r>>c>>k;
    
    for (int i=0;i<r;i++){
        for (int j=0;j<c;j++){
            scanf("%1s",&x);
            if (x=='T'){
                visit[i][j]=true;
            }
        }
    }
    if (visit[r-1][0]){
        cout<<"0";
        return 0;
    }
    dfs(r-1,0,1);
    cout<<result;
}

