#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int V, E, K;
const int INF = 987654321;

struct Node
{
    int w, idx;
    bool operator < (const Node &b) const
    {
        return w > b.w;
    }
};

vector <Node> graph[20001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> V >> E >> K;
    int u, v, w;
    while (E--)
    {
        cin >> u >> v >> w;
        graph[u].push_back({w, v});
    }

    vector<int> cache(V + 1, INF);
    cache[K] = 0;
    priority_queue<Node> pq;
    pq.push({0, K});

    while (!pq.empty())
    {
        Node curr = pq.top();
        pq.pop();
        if (curr.w > cache[curr.idx])
            continue;

        for (const auto &next : graph[curr.idx])
        {
            if (next.w + curr.w < cache[next.idx])
            {
                cache[next.idx] = next.w + curr.w;
                pq.push({cache[next.idx], next.idx});
            }
        }
    }
    for (int i = 1; i <= V; i++)
    {
        if (cache[i] == INF)
            cout << "INF" << '\n';
        else
            cout << cache[i] << '\n';
    }

    return 0;
}
