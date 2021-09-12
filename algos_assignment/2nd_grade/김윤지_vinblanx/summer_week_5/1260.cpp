#include <iostream>
#include <queue>

using namespace std;

#define MAX 1001
 
int N, M, V;
int map[MAX][MAX];
bool visited[MAX];
queue<int> q;
 
void reset() {
    for (int i = 1; i <= N; i++) {
        visited[i] = 0;
    }
}
 
void DFS(int v) {
    visited[v] = true;
    cout << v << " ";
    
    for (int i = 1; i <= N; i++) {
        if (map[v][i] == 1 && visited[i] == 0) { 
            DFS(i);
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
            if (map[v][w] == 1 && visited[w] == 0) { 
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
        map[a][b] = 1;
        map[b][a] = 1;
    }
 
    reset();
    DFS(V);
    
    cout << '\n';
    
    reset();
    BFS(V);
 
    return 0;
}
