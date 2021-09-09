#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

int n, l, r;
int sum, cnt, ans=0;
int a[50][50];
int vis[50][50];
int nd[4][2]={{-1,0},{0,1},{1,0},{0,-1}};

vector<pair<int,int>> bfs(int sx, int sy){
    int x, y, nx, ny, diff;
    queue<pair<int,int>> q;
    vector<pair<int,int>> v;

    vis[sx][sy]=1;
    sum+=a[sx][sy];
    q.push(make_pair(sx, sy));
    v.push_back(make_pair(sx,sy));
    while(!q.empty()){
        x=q.front().first;
        y=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            nx=x+nd[i][0];
            ny=y+nd[i][1];
            if(nx>=0 && nx<n && ny>=0 && ny<n){
                diff=(a[nx][ny]-a[x][y]<0)?a[x][y]-a[nx][ny]:a[nx][ny]-a[x][y];
                if(diff>=l && diff<=r && vis[nx][ny]==0){
                    vis[nx][ny]=1;
                    sum+=a[nx][ny];
                    v.push_back(make_pair(nx,ny));
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
    return v;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> l >> r;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> a[i][j];
        }
    }
    while(true){
        cnt=0;
        memset(vis, 0, sizeof(vis));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==0){
                    sum=0;
                    vector<pair<int,int>> uni = bfs(i, j);
                    if(uni.size()>1){
                        cnt++;
                        sum=sum/uni.size();
                        for(pair<int,int> p:uni){
                            a[p.first][p.second]=sum;
                        }
                    }
                }
            }
        }
        if(cnt==0)
            break;
        else
            ans++;
    }
    cout << ans;
}
