#include <iostream>
#include <queue>
using namespace std;
#define MAX 1001
 
int N, M, V;    // 정점개수, 간선개수, 시작정점
int map[MAX][MAX];    // 인접 행렬 그래프
bool visited[MAX];    // 정점 방문 여부
queue<int> q;
 
void reset() {
    for (int i = 1; i <= N; i++) {
        visited[i] = 0;
    }
}    // 정점 방문 여부 확인을 위해 각 원소를 0으로 초기화
 
void DFS(int v) {
    visited[v] = true;
    cout << v << " ";
    
    for (int i = 1; i <= N; i++) {
        if (map[v][i] == 1 && visited[i] == 0)    // 현재 정점과 연결되어있고 방문되지 않았으면
        {
            DFS(i);    // 재귀호출
        }
    }
}
 
void BFS(int v) {
    q.push(v);
    visited[v] = true;
    cout << v << " ";
 
    while (!q.empty()) {
        v = q.front();
        q.pop();
        
        for (int w = 1; w <= N; w++) {
            if (map[v][w] == 1 && visited[w] == 0)    // 현재 정점과 연결되어있고 방문되지 않았으면
            {
                q.push(w);
                visited[w] = true;
                cout << w << " ";
            }
        }
    }
}
 
int main() {
    cin >> N >> M >> V;
 
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        map[a][b] = map[b][a] = 1;
    }    // 두 정점의 간선이 연결된 경우 
 
    reset();
    DFS(V);
    
    cout << '\n';
    
    reset();
    BFS(V);
 
    return 0;
}
