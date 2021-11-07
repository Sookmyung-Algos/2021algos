#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

#define INF 1e9
#define MAX 110

using namespace std;

int n, m;
int dist[MAX][MAX];
int mapp[MAX][MAX];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void dijikstra(){
    
    //어디서 왔는지, 그 가중치가 얼마인지
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    
    pq.push({0, {1, 1}});
    
    while(!pq.empty()){
        int cost = pq.top().first;
        
        int node_x = pq.top().second.second;
        int node_y = pq.top().second.first;
        
        pq.pop();
        
        for(int i = 0; i < 4; i++){
            int next_x = node_x + dx[i];
            int next_y = node_y + dy[i];
            
            if(next_x > m || next_y > n || next_x <= 0 || next_y <= 0){
                continue;
            }
            
            int next_cost = cost + mapp[next_y][next_x];
            
            if(dist[next_y][next_x] > next_cost){
                //cout << "here\n";
                dist[next_y][next_x] = next_cost;
                pq.push({next_cost, {next_y, next_x}});
            }
            
        }
        
    }
    
}

int main(){
    
    cin >> m >> n;
    
    for(int i = 0; i <MAX; i++){
        for(int j = 0; j< MAX; j++){
            dist[i][j] = INF;
        }
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            scanf("%1d", &mapp[i][j]);
        }
    }
    //cout << "complete\n";
    
    dist[1][1] = 0;
    dijikstra();

    //cout << "complete\n";
    
    cout << dist[n][m];
    
}
