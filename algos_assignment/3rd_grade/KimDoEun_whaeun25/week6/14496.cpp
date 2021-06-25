#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
#include<queue>
#include<vector>

using namespace std;

int a, b, n, m;

vector<vector<int>> change;
vector<int>v;
vector<int> dist;

int solve(){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    pq.push({0,a});
    
    dist[a] = 0;
    
    while(!pq.empty()){
        int cnt = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        
        if(cnt <= dist[node]){
            for(int i = 0; i < change[node].size(); i++){
                int next = change[node][i];
                //cout << change[node][i];
                
                if(cnt + 1 < dist[next]){
                    dist[next] = cnt + 1;
                    pq.push({cnt+1, next});
                }
            }
        }
    }
    
    return dist[b];
}

int main(){
    
    cin >> a >> b >> n >> m;
    
    for(int i =0; i <= n; i++){
        dist.push_back(1e9);
        change.push_back(v);
    }
    
    for(int i = 0; i < m; i++){
        int x, y;
        
        cin >> x >> y;
        
        change[x].push_back(y);
        change[y].push_back(x);
        
    }
    
    int ans = solve();
    
    if(ans == 1e9){
        cout << -1;
    }else{
        cout << ans;
    }
    
}
