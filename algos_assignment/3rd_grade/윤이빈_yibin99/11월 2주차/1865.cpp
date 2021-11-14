#include <iostream>
#include <vector>
using namespace std;

vector<pair<int,pair<int,int>>> edge;
int dist[501];
int n, m, w;

bool BellmanFord(){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<edge.size();j++){
            int u=edge[j].second.first;
            int v=edge[j].second.second;
            int cost=edge[j].first;
            
            if(dist[v]>dist[u]+cost) dist[v]=dist[u]+cost;
        }
    }

    for(int j=0;j<edge.size();j++){
        int u=edge[j].second.first;
        int v=edge[j].second.second;
        int cost=edge[j].first;

        if(dist[v]>dist[u]+cost)
            return true;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int TC;
    cin >> TC;
    while(TC>0){
        cin >> n >> m >> w;
        edge.clear();
        fill(dist, dist+501, 0);
        for(int i=0;i<m;i++){
            int s, e, t;
            cin >> s >> e >> t;
            edge.push_back({t,{s,e}});
            edge.push_back({t,{e,s}});
        }
        for(int i=0;i<w;i++){
            int s, e, t;
            cin >> s >> e >> t;
            edge.push_back({-t,{s,e}});
        }
        if(BellmanFord()) cout << "YES" << "\n";
        else cout << "NO" << "\n";
        TC--;
    }
}
