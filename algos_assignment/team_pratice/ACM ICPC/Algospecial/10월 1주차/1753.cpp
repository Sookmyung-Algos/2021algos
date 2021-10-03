#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 20001
#define INF 1e9

using namespace std;

int visited[MAX];
int dist[MAX];

vector<pair<int, int>> edge[MAX];

int v, e, k;

void dijkstra(){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
    
    pq.push({0, k});
    
    dist[k] = 0;
    
    while(!pq.empty()){
        int cost = pq.top().first;
        int node = pq.top().second;
        
        pq.pop();
        
        for(int i = 0; i < edge[node].size(); i++){
            int next = edge[node][i].first;
            int next_cost = edge[node][i].second;
            
            if(dist[next] > cost + next_cost){
                dist[next] = cost + next_cost;
                pq.push({dist[next], next});
            }
        }
    }
    
}

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> v >> e >> k;
    
    for(int i = 0; i < e; i++){
        //a에서 b로 가는 가중치가 w이다.
        int a, b, w;
        
        cin >> a >> b >> w;
        
        edge[a].push_back({b, w});
    }
    
    //dist 배열 초기화
    for(int i = 1; i <= v; i++){
        dist[i] = INF;
    }
    
    dijkstra();
    
    for(int i = 1; i <= v; i++){
        if(dist[i] == INF){
            cout << "INF\n";
        }
        else{
            cout << dist[i] << "\n";
        }
    }
    
    
}
