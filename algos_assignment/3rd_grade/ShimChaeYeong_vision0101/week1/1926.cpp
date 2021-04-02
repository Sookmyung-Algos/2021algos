#include <iostream>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;
// pair의 값을 X, Y로 불러옴.
#define X first
#define Y second

int board[502][502]; // 그려짐 = 1, 안 그려짐 = 0
bool vis[502][502]; // 방문하면 1
int n, m; // 행, 열, 
int num = 0; // 그림 수
int area = 0;
int max_area = 0; // 가장 넓은 그림
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n >> m; // 행과 열 입력 받음
  
  queue<pair<int,int> > Q;

  for(int i=0; i<n; i++){ // 도화지의 그림 입력 받기
    for(int j=0; j<m; j++){
      cin >> board[i][j];
    }
  }
  
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      if(vis[i][j] == 1 || board[i][j] == 0) continue; // 방문 했거나, 그림이 안 그려져 있는 경우
        num++;
        Q.push({i,j});
        vis[i][j] = 1; // 방문 표시
        while(!Q.empty()){ // bfs
          pair<int, int> cur = Q.front(); Q.pop();
          area++;
          for(int dir=0; dir<4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // board 경계를 넘었을 경우
            if(vis[nx][ny] || board[nx][ny] != 1) continue;
            vis[nx][ny] = 1;
            Q.push({nx, ny});
            
          }
        }
        max_area = max(area, max_area); area = 0; // 가장 큰 그림 찾기
      
    }
  }
  cout << num << "\n" << max_area;
}
