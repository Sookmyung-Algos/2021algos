#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int m, n;
int tomato[1001][1001];
int tomato_time[1001][1001] = {0,};
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
queue < pair<int, int> > q;

void bfs(){
    while (!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx>=0 && nx<n && ny>=0 && ny<m && tomato[nx][ny]==0){
                tomato[nx][ny] = 1;
                q.push(make_pair(nx, ny));
                tomato_time[nx][ny] = tomato_time[x][y]+1;
            }
        }
    }
}

int main(){
    int max=0;
    cin >> m >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> tomato[i][j];
            if(tomato[i][j]==1)
                q.push(make_pair(i, j));
        }
    }
    bfs();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(tomato[i][j]==0){
                cout << -1;
                return 0;
            }
            if(max<tomato_time[i][j])
                max=tomato_time[i][j];
        }
    }
    cout << max;
}
