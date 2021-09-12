//1926 그림

#include <iostream> 
#include <algorithm> 
using namespace std; 
 
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};

int N, M; 
int area, result; 
int arr[500][500]; 
bool visited[500][500]; 

void DFS(int y, int x) 
{ 
    area++; 
    visited[y][x] = true; 
    for (int i = 0; i < 4; i++) 
    { 
        int nextY = y + dy[i]; 
        int nextX = x + dx[i]; 
        if(0<=nextY && nextY < N && 0<=nextX && nextX<M) 
            if (!visited[nextY][nextX] && arr[nextY][nextX]) 
                DFS(nextY, nextX); 
    } 
} 

int main(void) 
{ 
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0); 
    cin >> N >> M; 
    for (int i = 0; i < N; i++) 
        for (int j = 0; j < M; j++) 
            cin >> arr[i][j]; 
    
    int cnt = 0; 
    for(int i=0; i<N; i++) 
        for(int j=0; j<M; j++) 
            if (!visited[i][j] && arr[i][j]) 
            { 
                area = 0; // 현재 그림 크기 측정 위해 초기화 
                DFS(i, j); 
                result = max(result, area); 
                cnt++; 
            } 
    cout << cnt << "\n" << result << "\n"; 
    return 0; 
}
