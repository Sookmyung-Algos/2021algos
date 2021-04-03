#include <iostream>
#include <vector>
using namespace std;

vector<int> graph[1001];
bool vis[1001] = {false, };

void dfs(int n){
    vis[n] = true;
    for(int next:graph[n]){
        if(!vis[next])
            dfs(next);
    }
}

int main(){
    int n, m, u, v;
    int cnt = 0;
    cin >> n >> m;

    for(int i=0;i<m;i++){
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i);
            cnt++;
        }
    }
    cout << cnt;
}
