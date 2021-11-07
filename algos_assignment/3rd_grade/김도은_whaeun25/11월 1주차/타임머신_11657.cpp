#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<cmath>

#define INF 1e9
#define MAX 510

using namespace std;

int n, m;
long long dist[MAX];

vector<pair<pair<int, int>, int>> edge;

int main(){
    
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++){
        dist[i] = INF;
    }
    
    for(int i = 0; i< m; i++){
        int a, b, c;
        
        cin >> a >> b >> c;
        
        edge.push_back({{a, b}, c});
    }
    
    dist[1] = 0;
    
    for(int i = 1; i < n; i++){
        for(int j = 0 ; j< edge.size(); j++){
            
            int a = edge[j].first.first;
            int b = edge[j].first.second;
            int cost = edge[j].second;
            
            if(dist[a] == INF){
                continue;
            }
            
            if(dist[b] > dist[a] + cost){
                dist[b] = dist[a] + cost;
            }
        }
    }
    
    for(int i =0; i< edge.size(); i++){
        
        int a = edge[i].first.first;
        int b = edge[i].first.second;
        int cost = edge[i].second;
        
        if(dist[a] == INF){
            continue;
        }
        
        if(dist[b] > dist[a] + cost){
            cout << -1 <<"\n";
            return 0;
        }
    }
    
    for(int i = 2; i <= n; i++){
        if(dist[i] == INF){
            cout << -1 << "\n";
        }
        else{
            cout << dist[i] << "\n";
        }
    }
    
    
}
