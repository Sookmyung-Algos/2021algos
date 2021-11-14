#include <iostream>
#include <vector>
using namespace std;
#define INF 0x7FFFFFFF

int n, m;
vector<pair<int,pair<int,int>>> edge;
long long dist[501];

bool BellmanFord(){
    dist[1]=0;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<edge.size();j++){
            int s = edge[j].second.first;
            int e = edge[j].second.second;
            long long cost = edge[j].first;
            if(dist[s]!=INF && dist[e]>dist[s]+cost)
                dist[e]=dist[s]+cost;
        }
    }
    for(int j=0;j<edge.size();j++){
        int s = edge[j].second.first;
        int e = edge[j].second.second;
        long long cost = edge[j].first;
        if(dist[s]!=INF && dist[e]>dist[s]+cost){
            dist[e]=-INF;
            return false;
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    fill(dist, dist+501, INF);
    for(int i=0;i<m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        edge.push_back({c, {a,b}});
    }
    if(BellmanFord()){
        for(int i=2;i<=n;i++){
            if(dist[i]!=INF) cout << dist[i] << "\n";
            else cout << -1 << "\n";
        }
    }
    else cout << -1;
}
