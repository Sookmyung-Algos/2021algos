#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int dy[]= {1, -1, 0, 0}, dx[]= {0, 0, 1, -1};
vector<vector<int>> arr;
vector<vector<bool>> mark;
vector<int> parent;

void bfs(int i, int j, int pnum){
    queue<pair<int, int>> q;
    q.push({i, j});
    mark[i][j]=true;
    queue<pair<int, int>> path;
    path.push({i, j});
    int cnt=1;
    while(!q.empty()){
        int y= q.front().first;
        int x= q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int yy= y+dy[i];
            int xx= x+dx[i];
            if(yy<0 || yy>=n || xx<0 || xx>=m)
                continue;
            if(mark[yy][xx])
                continue;
            if(!arr[yy][xx])
                continue;
            mark[yy][xx]=true;
            q.push({yy, xx});
            path.push({yy, xx});
            cnt++;
        }
    }
    while(!path.empty()){
        int cy= path.front().first;
        int cx= path.front().second;
        path.pop();
        arr[cy][cx]= pnum;
    }
    parent.push_back(cnt);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    arr.assign(n, vector<int>(m, 0));
    mark.assign(n, vector<bool>(m, false));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }
    parent.push_back(0);
    int parentcnt=1;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j] && !mark[i][j]){
                bfs(i, j, parentcnt++);
            }
        }
    }
    vector<bool> parentmark(parent.size(), false);
    int result=0;
    for(int y=0; y<n; y++){
        for(int x=0; x<m; x++){
            if(!arr[y][x]){
                int tmp=1;
                parentmark.assign(parent.size(), false);
                for(int i=0; i<4; i++){
                    int yy= y+dy[i];
                    int xx= x+dx[i];
                    if(yy<0 || yy>=n || xx<0 || xx>=m)
                        continue;
                    if(parentmark[arr[yy][xx]])
                        continue;
                    if(!arr[yy][xx])
                        continue;
                    parentmark[arr[yy][xx]]= true;
                    tmp+= parent[arr[yy][xx]];
                }
                if(tmp>result)
                    result= tmp;
            }
        }
    }
    cout<<result<<"\n";
    return 0;
}
