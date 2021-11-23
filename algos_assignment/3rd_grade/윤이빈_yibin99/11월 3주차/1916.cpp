#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 0x7fffffffffffffff

int n, m;
vector<pair<int, int>> bus[1001];//cost, end
long long dist[1001];

void dijkstra(int source){
    for(int i=1;i<=n;i++) dist[i]=INF;
    priority_queue<pair<long long,int>> pq;
    pq.push({0, source});
    dist[source]=0;

    while(!pq.empty()){
        long long cost = -pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if(cost>dist[u])    continue;
        
        for(int i=0;i<bus[u].size();i++){
            int c = bus[u][i].first;
            int v = bus[u][i].second;
            if(dist[v]>dist[u]+c){
                dist[v]=dist[u]+c;
                pq.push({-dist[v], v});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int s, e, c;
    int source, dest;

    cin >> n >> m;
    for(int i=0;i<m;i++){
        cin >> s >> e >> c;
        bus[s].push_back({c, e});
    }
    cin >> source >> dest;
    dijkstra(source);
    cout << dist[dest];
}
