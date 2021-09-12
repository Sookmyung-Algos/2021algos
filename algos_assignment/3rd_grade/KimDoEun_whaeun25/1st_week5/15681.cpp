#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> graph;
vector<int> v;
vector<int> query;


int answer[100001];
int visited[100001];

int n, r, q;

int dfs(int node){
    if(answer[node] != 0){
        return answer[node];
    }
    
    visited[node] = 1;
    int result = 1;
    
    for(int i = 0; i < graph[node].size(); i++){
        int next = graph[node][i];
        if(visited[next] == 1){
            continue;
        }
        result += dfs(next);
    }
    
    answer[node] = result;
    
    return result;
}

int main(){
  
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    
    cin >> n >> r >> q;
    
    for(int i =0; i<= n; i++){
        graph.push_back(v);
    }

    for(int i =0; i < n-1; i++){
        int u, v2;
        
        cin >> u >> v2;
        
        graph[u].push_back(v2);
        graph[v2].push_back(u);
    }
    
    for(int i =0; i<q; i++){
        int a;
        cin >> a;
        query.push_back(a);
    }
    
    answer[r] = dfs(r);
    
    for(int i =0; i<q; i++){
        cout << answer[query[i]] << "\n";
    }
    
}
