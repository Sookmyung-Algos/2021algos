#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<vector<pair<int,int>>>edge;
vector<pair<int,int>>v;
vector<int>visited;

int max_degree = 0;
int max_node = 0;

void dfs(int node, int parent, int degree){
    if (visited[node]){
        return;
    }
    visited[node] = true;
    for(int i =0; i< edge[node].size();i++){
        
        if(edge[node][i].first == parent){
            continue;
        }
        
        dfs(edge[node][i].first, node, degree+edge[node][i].second);
    }
    if(max_degree < degree){
        max_degree = degree;
        max_node = node;
    }
}

int main(){
    int n;
    
    cin >>n;
    
    edge.push_back(v);
    visited.push_back(0);
    
    for(int i =0; i<n;i++){
        edge.push_back(v);
        visited.push_back(0);
    }

    
    for(int i =0; i<n;i++){
        int node_num, linked_num, degree;
        cin >> node_num;
        cin >> linked_num;
        while(linked_num != -1){
            cin >> degree;
            edge[node_num].push_back(make_pair(linked_num, degree));
            cin >> linked_num;
        }
    }
    
    dfs(1,-1,0);
    
    for(int i =0; i<=n;i++){
        visited[i] = 0;
    }
    
    dfs(max_node,-1,0);
    
    cout << max_degree;
    
}
