#include <iostream>
#include <queue>
using namespace std;
#define MAX_VALUE 1001            
//N이 1~1000 이므로 크기는 1001까지 선언

int N, M, V;                    
int matrix[MAX_VALUE][MAX_VALUE];    
//인접행렬 배열 선언
int visit[MAX_VALUE];            
//visit 배열
 
void dfs(int v) {
    cout << v << ' ' ;
    visit[v] = 1;            
    //방문한 노드를 visit 0에서 1로 변경
    for(int i=1; i<=N; i++) {
        if(visit[i] == 1 || matrix[v][i] == 0)     
            continue;
        dfs(i);                
        //재귀를 사용
    }
}
 
void bfs(int v) {
    queue<int> q;            
    //bfs에서는 큐를 사용한다.
    q.push(v);
    visit[v] = 0;            
    //방문한 노드를 visit 1에서 0으로 변경
    while(!q.empty()) {
        v = q.front();
        cout << q.front() << ' ';
        q.pop();
        for(int i=1; i<=N; i++) {
            if(visit[i] == 0 || matrix[v][i] == 0)
                continue;
            q.push(i);
            visit[i] = 0;
        }
    }
}
 
int main() {
    int x, y;
    cin >> N >> M >> V;            
    for(int i=0; i<M; i++) {    
        cin >> x >> y;            
        matrix[x][y] = matrix[y][x] = 1;    
        //인접행렬을 표시한다.
    }
    dfs(V);            
    cout << '\n';
    bfs(V);
    return 0;
}
