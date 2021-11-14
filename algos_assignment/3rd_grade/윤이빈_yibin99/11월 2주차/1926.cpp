#include <iostream>
#include <queue>
using namespace std;

int n, m;
int paper[500][500], dir[4][2]={{0,1}, {1,0}, {0,-1}, {-1,0}};
bool vis[500][500];
int maxVal=0, cnt=0;

void bfs(int sr, int sc){
    queue<pair<int,int>> q;
    q.push({sr, sc});
    vis[sr][sc]=true;
    int area=1;
    while(!q.empty()){
        int r=q.front().first;
        int c=q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int nr=r+dir[i][0];
            int nc=c+dir[i][1];
            if(nr<0 || nr>=n || nc<0 || nc>=m || paper[nr][nc]==0 || vis[nr][nc]) continue;
            q.push({nr,nc});
            vis[nr][nc]=true;
            area++;
        }
    }
    if(area>maxVal) maxVal=area;
    cnt++;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> paper[i][j];
            vis[i][j]=false;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(paper[i][j]==1 && vis[i][j]==false){
                bfs(i, j);
            }
        }
    }
    cout << cnt << "\n" << maxVal;
}
