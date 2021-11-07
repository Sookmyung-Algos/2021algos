#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define MAX 50500
#define INF 1e9

using namespace std;

vector<vector<pair<int, int>>> mapp(MAX);

int visited[MAX] = {0, };
int dist[MAX];

void dijikstra(){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;;
    
    pq.push({0, 1});
    dist[1] = 0;
    
    //cout << "here\n";
    
    while(!pq.empty()){
        int x = pq.top().first;
        int y = pq.top().second;
        
        pq.pop();
        
        if(visited[y]){
            continue;
        }
        
        visited[y] = 1;
        
        for(int i = 0; i < mapp[y].size(); i++){
            
            int next_x = mapp[y][i].first;
            int next_y = mapp[y][i].second;
            
            if(dist[next_y] > dist[y] + next_x){
                dist[next_y] = dist[y] + next_x;
                pq.push({dist[next_y], next_y});
            }
        }
        
    }
}

int main(){
    
    int n, m;
    
    cin >> n >> m;
    
    for(int i = 0; i <  MAX; i++){
        dist[i] = INF;
    }
    

    int  a, b, c;
    
    for(int i = 0; i< m; i++){
        cin >> a >> b >> c;
        
        mapp[a].push_back({c, b});
        mapp[b].push_back({c, a});
    }
    
    dijikstra();
    
    cout << dist[n];
    
}
