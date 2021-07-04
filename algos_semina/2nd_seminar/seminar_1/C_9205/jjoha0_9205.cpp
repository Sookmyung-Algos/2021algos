#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 102;

int n;
vector<int> graph[MAX];
bool visited[MAX];

int manhattan(pair<int, int> p1, pair<int, int> p2)
{
    return abs(p1.first-p2.first)+abs(p1.second-p2.second);
}

void DFS(int node)
{
    visited[node]=true;
    
    for (int i = 0; i < graph[node].size(); i++)
    {
        int next = graph[node][i];
        if (visited[next]==false)
            DFS(next);
    }
}

int main(void)
{
    ios_base::sync_with_stdio(0);

    cin.tie(0); //cin 속도 향상

    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++)
    {
        for(int j=0; j<n+2; j++)
        {
            visited[j] = false;
            graph[j].clear();
        }
    
        cin >> n; //편의점 개수
        vector<pair<int,int>>v;
        
        for (int j = 0; j < n+2; j++)
        {
            int x, y;
            cin >> x >> y;
            
            v.push_back(make_pair(x, y));
        }
        for (int j = 0; j < n+2; j++)
        {
            for (int k = j+1; k < n+2; k++)
            {
                if (manhattan(v[j], v[k]) <= 50 * 20)
                {
                    graph[j].push_back(k);
                    graph[k].push_back(j);
                }
            }
        }
        DFS(0);
        if (visited[n+1])
            cout << "happy\n";
        else
            cout << "sad\n";
    }
    return 0;
}
