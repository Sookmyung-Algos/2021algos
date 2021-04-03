#include <iostream>
#include <queue>
using namespace std;

int m,n;
int v[1001][1001];
int t[1001][1001];
queue <pair<int,int>> q;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
void bfs();

int main() {
    int max=0;
    
    cin >> m >> n;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cin >> v[i][j];
            if (v[i][j]==1){
                q.push(make_pair(i,j));
            }
        }
    }
    bfs();
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (v[i][j] == 0){
                cout << -1;
                return 0;
            }
            if (max < t[i][j]) max = t[i][j];
        }
    }
    cout << max;
    return 0;
}
void bfs(){
    while (!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for (int i=0;i<4;i++){
            int next_x = x+dx[i];
            int next_y = y+dy[i];
            
            if (next_x >= 0 && next_y >= 0 && next_x < n && next_y < m && (v[next_x][next_y]==0)){
                v[next_x][next_y]=1;
                q.push(make_pair(next_x,next_y));
                t[next_x][next_y] = t[x][y]+1;
            }
        }
    }
}
