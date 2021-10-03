#include <iostream>
#include <string>
#include <queue>
using namespace std;

const int INF = 999999999;
const int MAX = 502;

int n, m;
long long dist[MAX];
vector<pair<pair<int, int>, int>> e;

void belman_ford(){
    dist[1]= 0;
    for(int i=1; i<n; i++){
        for(int j=0; j<e.size(); j++){
            int from= e[j].first.first;
            int to= e[j].first.second;
            int cost= e[j].second;
            if(dist[from] == INF)
                continue;
            if(dist[to]>dist[from]+cost)
                dist[to] = dist[from]+cost;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        dist[i]=INF;
    }
    for (int i = 0; i < m; i++){
        int from, to, cost;
        cin >> from >> to >> cost;
        e.push_back(make_pair(make_pair(from, to), cost));
    }
    belman_ford();
    for(int i=0; i<e.size(); i++){
        int from= e[i].first.first;
        int to= e[i].first.second;
        int cost= e[i].second;
        if(dist[from]==INF)
            continue;
        if(dist[to]>dist[from]+cost){
            cout<< -1 << "\n";
            return 0;
        }
    }
    for(int i=2; i<=n; i++){
        if(dist[i]==INF) 
            cout << -1 << "\n";
        else
            cout << dist[i] << "\n";
    }
    return 0;
}
