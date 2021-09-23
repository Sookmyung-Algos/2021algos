//https://scarlettb.tistory.com/76 코드 참고

#include <iostream>
#include <queue>
using namespace std;
#define MAX 1001

int N, M, V; //정점개수, 간선개수, 시작정점
int map[MAX][MAX]; // 그래프 정의하기 
bool isvisited[MAX]; //정점에 대한 방문여부 확인하기
queue<int> q;

void reset() {
    for (int i = 1; i <= N; i++) {
        isvisited[i] = 0;
    }
}

void DFS(int v) {
    isvisited[v] = true;
    cout << v << " ";

    for (int i = 1; i <= N; i++) {
        if (map[v][i] == 1 && isvisited[i] == 0) { //방문하지 않은 현재 정점과의 연결된 정점 찾기
            DFS(i);
        }
    }
}

void BFS(int v) {
    q.push(v);
    isvisited[v] = true;
    cout << v << " ";

    while (!q.empty()) {
        v = q.front();
        q.pop();

        for (int w = 1; w <= N; w++) {
            if (map[v][w] == 1 && isvisited[w] == 0) { //방문하지 않은 현재 정점과의 연결된 정점 찾기
                q.push(w);
                isvisited[w] = true;
                cout << w << " ";
            }
        }
    }
}

int main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);


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
