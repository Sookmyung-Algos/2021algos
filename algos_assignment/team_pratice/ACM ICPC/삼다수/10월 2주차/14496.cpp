#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

using pii = pair<int,int>;

int a, b, n, m;
vector <int> graph[1001];
vector <int> dist(1001);

int dijkstra(){
    priority_queue <pii,vector<pii>,greater<pii>> pq;
    pq.push({0,a});
    dist[a] = 0;
    while(!pq.empty()){
        int cur = pq.top().second;
        int cost = pq.top().first;
        pq.pop();
        if(cost > dist[cur]) continue;
        for(auto next : graph[cur]){
            if(cost + 1 < dist[next]){
                dist[next] = cost + 1;
                pq.push({cost+1,next});
            }
        }
    }
    if(dist[b] == INF) return -1;
    return dist[b];
}

int main(){
    cin >> a >> b;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) dist[i] = INF;
    for(int i = 0; i < m; i++){
        int u,v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    cout << dijkstra();
  
  return 0;
}
