#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int>graph[1010];

int visited[1010];

int n, r, q;

void dfs(int node){
    
    visited[node] = 1;
    
    for(int i = 0; i < graph[node].size(); i++){
        int next = graph[node][i];
        if(visited[next] == 1){
            continue;
        }
        dfs(next);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    
    int testcase;
    
    cin >> testcase;
    
    for(int t = 0; t < testcase; t++){
        
        for(int i =0; i< 1010; i++){
            graph[i].clear();
            visited[i] = 0;
        }
        
        int n, m;
        
        cin >> n >> m;
        
        int cnt = 0;
        
        for(int i =0; i<m; i++){
            int a, b;
            
            cin >>a>>b;
            
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        
        for(int i =1; i<=n; i++){
            if(!visited[i]){
                dfs(i);
                cnt++;
            }
        }
        
        if(m == n-1 && cnt == 1){
            cout << "tree\n";
        }else{
            cout << "graph\n";
        }
    }
}
