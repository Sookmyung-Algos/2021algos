// 1753(Gold 5) - 최단경로
#include <iostream>
#include <vector>
#include <queue>
#define MAX 20001
#define INF 1e9
using namespace std;

int V, E, K;  // v:정점 개수, e: 간선 개수, K: 시작 정점 번호
int u, v, e;  // u에서 v로 가는 가중치 e의 간선
vector<pair<int, int>> graph[MAX];  // graph[a] = {b,c} -> a에서 b로 가는 간선의 가중치가 c

vector<int> Dijkstra(){
    vector<int> dist(V+1, INF);
    
    priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;  // first:dist, second: vertex number
    dist[K] = 0;  // 시작정점의 초깃값은 0
    
    pq.push({dist[K], K});
    
    while(!pq.empty()){
        int cur = pq.top().second;
        int curDist = pq.top().first;
        
        pq.pop();
        
        if(dist[cur] < curDist)  // dist[cur]에 새로 값을 갱신해줄 필요가 없음
            continue;
            
        for(int i=0;i<graph[cur].size();i++){  // 인접 노드 하나씩 방문
            int next = graph[cur][i].first;
            int nextDist = graph[cur][i].second + curDist;  // start~cur 거리 + cur~next 거리
            
            // 최단 거리 갱신
            if(nextDist < dist[next]){
                dist[next] = nextDist;
                pq.push({nextDist, next});
            }
        }
    }
    return dist;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> V >> E;
    cin >> K;
    for(int i=0;i<E;i++){
        cin >> u >> v >> e;
        graph[u].push_back({v,e});
    }
    
    vector<int> result = Dijkstra();
    
    for(int i=1;i<result.size();i++){
        if(result[i] == INF)
            cout << "INF\n";
        else
            cout << result[i] << "\n";
    }
    
    return 0;
}
