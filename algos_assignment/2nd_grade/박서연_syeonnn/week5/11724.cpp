#include <iostream>
#include <vector>
using namespace std;
#define MAX 1001

int N,M;
vector<int> graph[MAX];
bool visited[MAX];


void DFS(int node)
{
    visited[node] = true;
    for (int i = 0; i < graph[node].size(); i++)
    {
        int next = graph[node][i];    // node에 연결된 다른 정점을 방문하기 위한 변수
        if (!visited[next])    // 방문한 적 없다면
            DFS(next);    // 재귀호출
    }
}

int main(void)
{
    cin >> N >> M;     // 정점의 개수, 간선의 개수

    for (int i = 0; i < M; i++)
    {
        int a, b;   
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }     // 간선의 양 끝점들

    int cnt = 0;

    for (int i = 1; i <= N; i++)
        if (!visited[i])
        {
            DFS(i);
            cnt++;    // 방문되지 않은 정점이 발견된다면 연결요소 개수 추가됨
        }

    cout << cnt << endl;
    return 0;
}
