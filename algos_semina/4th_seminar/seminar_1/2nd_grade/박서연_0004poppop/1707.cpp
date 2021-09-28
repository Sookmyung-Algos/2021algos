// 백준 1707 이분 그래프

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int K, V, E;
vector<int> graph[20001];
int nodeColor[20001];

/*
아직 방문하지 않음 = 0, 임의의 색1 = 1, 임의의 색2 = 2
기존 문제에서는 방문 여부를 true로 표현, 해당 문제에서는 노드 색들의 구분을 위해 달리 함
*/
void dfs(int nodeNum, int color)
{
    nodeColor[nodeNum] = color; // 초기 방문 노드는 아무 색으로 지정

    for (int i = 0; i < graph[nodeNum].size(); i++)
    {
        int next = graph[nodeNum][i];
        if (!nodeColor[next])   // 연결되는 노드를 방문하지 않았다면
        {
            dfs(next, 3 - color);   // 연결되는 노드는 반대되는 색으로 지정
        }
    }
}

// 이분 그래프는 서로 연결된 노드끼리 다른 색. 이분 그래프 여부 확인하는 함수
bool isBipartiteGraph(void)
{
    for (int i = 1; i <= V; i++)
    {
        for (int j = 0; j < graph[i].size(); j++)
        {
            int next = graph[i][j];

            if (nodeColor[i] == nodeColor[next])
                return false;
        }
    }
    return true;
}



int main()
{
    cin >> K;

    for (int i = 0; i < K; i++)
    {
        for (int j = 1; j < 20001; j++)
        {
            graph[j].clear();   // 테스트케이스가 1이상이므로 그래프 초기화
        }
        memset(nodeColor, 0, sizeof(nodeColor));    // 테스트케이스가 1이상이므로 방문기록 초기화

        cin >> V >> E;

        for (int j = 0; j < E; j++)
        {
            int node1, node2;
            cin >> node1 >> node2;

            graph[node1].push_back(node2);
            graph[node2].push_back(node1);
        }   // 두 정점을 잇는 간선들

        for (int j = 1; j <= V; j++)
        {
            if (nodeColor[j] == 0)
            {
                dfs(j, 1); // 시작하는 색은 임의로 정함
            }
        }
           
        if (isBipartiteGraph())
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
    return 0;
}
