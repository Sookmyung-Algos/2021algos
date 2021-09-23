#include <iostream>
using namespace std;

int map[101][101];    // 인접 행렬 그래프
int visited[101];     // 정점 방문 여부
int n, cnt;     // 컴퓨터(=정점) 개수, 1번 컴퓨터에 의해 감염되는 컴퓨터 수

void DFS(int node)
{
    visited[node] = 1;

    for (int i = 1; i <= n; i++) {
        if (map[node][i] == 1 && !visited[i])    // 현재 정점과 연결되어있고 방문되지 않았으면
        {
            cnt++;
            DFS(i);
        }
    }
}

int main() {
    int num;
    int a, b;
    cin >> n;
    cin >> num;

    for (int i = 0; i < num; i++) {
        cin >> a >> b;
        map[a][b] = map[b][a] = 1;    // 네트워크상 연결되어있는 컴퓨터 번호 쌍 = 두 정점의 간선이 연결된 경우 
    }

    DFS(1);    // 1번 컴퓨터가 바이러스에 감염
    cout << cnt << endl;
}
