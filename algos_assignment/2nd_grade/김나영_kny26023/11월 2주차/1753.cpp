#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 20000 + 1;
const int INF = 987654321;

int V, E, K;
vector<pair<int, int>> graph[MAX];

vector<int> dijkstra(int st, int vt){
    vector<int> dist(vt, INF);
    dist[st] = 0;
    
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, st));

    while (!pq.empty()){
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if (dist[cur] < cost)
            continue;
        for (int i = 0; i < graph[cur].size(); i++){
            int n = graph[cur][i].first;
            int nd = cost + graph[cur][i].second;
            if (dist[n] > nd){
                dist[n] = nd;
                pq.push(make_pair(-nd, n));
            }
        }
    } 
    return dist;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> V >> E >> K;
    V++;
    for (int i = 0; i < E; i++){
        int s, d, cost;
        cin >> s >> d >> cost;
        graph[s].push_back(make_pair(d, cost));
    }
    vector<int> result = dijkstra(K, V);
    for (int i = 1; i < V; i++){
        if (result[i] == INF)
            cout << "INF\n";
        else
            cout << result[i] << "\n";
    }
    return 0;
}
