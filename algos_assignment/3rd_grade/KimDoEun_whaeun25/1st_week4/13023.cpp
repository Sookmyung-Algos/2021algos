#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, m;

vector<vector<int>> edge;
vector<int>visited;
vector<int> v;

int max_degree = 0;
int max_node = 0;

void dfs(int node, int parent, int degree) {
        
    visited[node] = true;
    if(max_degree <= degree){
        max_degree = degree;
        if(max_degree>=4){
            return;
        }
    }
    for(int i =0; i< edge[node].size();i++){
        if(visited[edge[node][i]]){
            continue;
        }
        dfs(edge[node][i], node, degree+1);
    }
    visited[node] = false;
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        edge.push_back(v);
        visited.push_back(0);
    }

    for (int j = 1; j <= m; j++) {
        int a, b;

        cin >> a >> b;

        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    
    for(int i =0; i < n; i++){
        dfs(i, -1, 0);
        for(int i =0; i<n;i++){
            visited[i] = 0;
        }
        if(max_degree >= 4){
            break;
        }
    }
    
    if(max_degree >= 4 ){
        cout << "1";
    }
    else{
        cout << "0";
    }
    
}
