#include <iostream> 
#include <algorithm> 

using namespace std; 

const int MAX = 500; 

typedef struct { 
  int y, x; 
}Dir; 

Dir moveDir[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} }; 

int N, M; 
int area, res; 
int arr[MAX][MAX]; 
bool visit[MAX][MAX]; 
void DFS(int y, int x) { 
  area++; 
  visit[y][x] = true; 
  for (int i = 0; i < 4; i++) { 
    int nextY = y + moveDir[i].y; 
    int nextX = x + moveDir[i].x; 
    if(0<=nextY && nextY < N && 0<=nextX && nextX<M) 
      if (!visited[nextY][nextX] && arr[nextY][nextX]) DFS(nextY, nextX); 
  } 
} 

int main(void) { 
  ios_base::sync_with_stdio(0); 
  cin.tie(0); 
  cin >> N >> M; 
  for (int i = 0; i < N; i++) 
    for (int j = 0; j < M; j++) 
      cin >> arr[i][j]; 
  int cnt = 0; 
  for(int i=0; i<N; i++) 
    for(int j=0; j<M; j++) 
      if (!visit[i][j] && arr[i][j]) { 
        area = 0; //초기화
        DFS(i, j); 
        res = max(res, area); 
        cnt++; 
      } 
  cout << cnt << "\n" << res << "\n"; 
  return 0;
}
