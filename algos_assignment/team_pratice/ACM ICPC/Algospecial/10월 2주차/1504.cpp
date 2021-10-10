#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

#define INF 1e9
#define MAX 810

using namespace std;

int n, e;

int dist1[MAX];
int dist2[MAX];

int d1_w, d2_w;

//int visited[MAX][MAX];

vector<vector<pair<int, int>>> road;
vector<pair<int, int>> v;

void dijikstra1(int start, int end, int weight){
    
    //어디서 왔는지, 그 가중치가 얼마인지
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    pq.push({weight, start});
    
    while(!pq.empty()){
        int cost = pq.top().first;
        int node = pq.top().second;
        
       // cout << "node: " << node << " cost: " << cost << "\n";
        if(node == end){
            break;
        }
        
        pq.pop();
        
        for(int i = 0; i < road[node].size(); i++){
            int next = road[node][i].first;
            int next_cost = road[node][i].second;
            
            if(dist1[next] > cost + next_cost){
                dist1[next] = cost + next_cost;
                pq.push({dist1[next], next});
            }
            
        }
    }
    
}

void dijikstra2(int start, int end, int weight){
    
    //어디서 왔는지, 그 가중치가 얼마인지
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    pq.push({weight, start});
    
    while(!pq.empty()){
        int cost = pq.top().first;
        int node = pq.top().second;
        
        //cout << "node: " << node << " cost: " << cost << "\n";
        if(node == end){
            break;
        }
        
        pq.pop();
        
        for(int i = 0; i < road[node].size(); i++){
            int next = road[node][i].first;
            int next_cost = road[node][i].second;
            
            if(dist2[next] > cost + next_cost){
                dist2[next] = cost + next_cost;
                pq.push({dist2[next], next});
            }
            
        }
    }
    
}

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> e;
    
    //초기화
    for(int i = 0; i <= n; i++){
        dist1[i] = INF;
        dist2[i] = INF;
    }
    
    for(int i = 0; i <= n; i++){
        road.push_back(v);
    }
    
    for(int i = 0; i < e; i++){
        int a, b, c;
        
        cin >> a >> b >> c;
        
        road[a].push_back({b, c});
        road[b].push_back({a, c});
    }
    
    int point1, point2;
    
    cin >> point1 >> point2;
    
    dist1[1] = 0;
    dist2[1] = 0;
    
    dijikstra1(1, point1, 0);
    d1_w = dist1[point1];
    for(int i = 0; i <= n; i++){
        dist1[i] = INF;
    }
    dist1[point1] = d1_w;
    
    dijikstra1(point1, point2, d1_w);
    d1_w = dist1[point2];
    for(int i = 0; i <= n; i++){
        dist1[i] = INF;
    }
    dist1[point2] = d1_w;

    dijikstra1(point2, n, d1_w);
    
    dijikstra2(1, point2, 0);
    d1_w = dist2[point2];
    for(int i = 0; i <= n; i++){
        dist2[i] = INF;
    }
    dist2[point2] = d1_w;
    
    dijikstra2(point2, point1, d1_w);
    d1_w = dist2[point1];
    for(int i = 0; i <= n; i++){
        dist2[i] = INF;
    }
    dist2[point1] = d1_w;

    dijikstra2(point1, n, d1_w);
    
    //cout << "1: " << dist1[n] << " 2: " << dist2[n] << "\n";
    
    if(dist1[n] > dist2[n]){
        cout << dist2[n];
    }
    else if(dist1[n] < dist2[n]){
        cout << dist1[n];
    }
    else if(dist1[n] == INF && dist2[n] == INF){
        cout << "-1";
    }
    else{
        cout << dist1[n];
    }
    
}
