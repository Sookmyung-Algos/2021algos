#include <iostream>
#include <queue>
using namespace std;

int n,m;
int graph[1000][1000];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

queue<pair<int,int>> q;

void bfs(){
    while (!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for (int i=0;i<4;i++){
            int nx = dx[i]+x;
            int ny = dy[i]+y;
            if (nx >= 0 && nx < n && ny >= 0 && ny < m){
                if (graph[nx][ny]==1){
                    q.push({nx,ny});
                    graph[nx][ny] = graph[x][y]+1;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cin >> graph[i][j];
            if (graph[i][j] == 2) q.push({i,j});
        }
    }

    bfs();

    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (graph[i][j]==0) cout << graph[i][j] << " ";
            else cout << graph[i][j]-2 << " ";
        }
        cout << endl;
    }
}
