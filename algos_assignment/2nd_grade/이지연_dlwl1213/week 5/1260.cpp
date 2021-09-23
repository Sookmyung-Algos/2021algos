#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N, M, V;
int adjacent[1001][1001];
bool visited[1001];
queue<int> q;

void DFS(int idx) {
        cout << idx << " ";
        for(int i=1; i<=N; i++)
                 if (adjacent[idx][i] && !visited[i]) {
                         visited[i] = 1;                
                         DFS(i);  //인접한 노드에 대해서 또 다시 DFS
                 }
}

void BFS(int idx) {
        q.push(idx);
        visited[idx] = 1;

        while (!q.empty()) {
                 idx = q.front();
                 q.pop();

                 cout << idx << " ";

                 for(int i=1; i<=N; i++)   //BFS -> 해당 노드에 인접한 노드들을 모두 추가한 뒤 진행 
                         if (adjacent[idx][i] && !visited[i]) {
                                 visited[i] = 1;
                                 q.push(i);
                         }
        }
}

int main(void) {
        cin >> N >> M >> V;
        for (int i = 0; i < M; i++) {
                 int s, e;
                 cin >> s>> e;
                 adjacent[s][e] = 1;
                 adjacent[e][s] = 1;
        }
        visited[V] = 1; //V에서 시작하므로
        DFS(V);
        cout << endl;

        memset(visited, false, sizeof(visited));
        BFS(V);
        cout << endl;

        return 0;
}
