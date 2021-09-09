#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>

#define INF 1e9

using namespace std;

int root_node;

vector<vector<pair<int, int>>> tree;
vector<pair<int, int>>v2;

vector<vector<int>> diff_height;
vector<int>v;

int visited[10010];
int dis[10010];
int difference[10010];
int parent[10010];

int max_height = 0;

int n, h;


void dfs(int node, int dh, int d){
    
    visited[node] = 1;
    dis[node] = d;
    
    diff_height[dh].push_back(node);
    
    if(!tree[node].size()){
        difference[node] = d - h;
    }
    
    for(int i = 0; i < tree[node].size(); i++){
        if(visited[tree[node][i].first] == 0){
            dfs(tree[node][i].first, dh + 1, d + tree[node][i].second);
        }
    }
    
}

int main(){
    
    cin >> n >> h;
    
    for(int i = 0; i <= n; i++){
        tree.push_back(v2);
        diff_height.push_back(v);
    }
    
    for(int i = 1; i <= n; i++){
        int p, d;
        
        cin >> p >> d;
        
        if(p == 0 && d == 0){
            root_node = i;
            continue;
        }
        
        parent[i] = p;
        
        tree[p].push_back({i, d});
    }
    
    int ans = 0;
    
    dfs(root_node, 0, 0);
    
    for(int i = (int)diff_height.size() - 1; i >= 0; i--){
        for(int j = 0; j < diff_height[i].size(); j++){
            if(dis[parent[diff_height[i][j]]] >= difference[diff_height[i][j]]){
                difference[parent[diff_height[i][j]]] = max(difference[diff_height[i][j]], difference[parent[diff_height[i][j]]]);
            }
            else{
                difference[parent[diff_height[i][j]]] = dis[parent[diff_height[i][j]]];
                ans += difference[diff_height[i][j]] - dis[parent[diff_height[i][j]]];
            }
        }
    }
    
    cout << ans;
    
}
