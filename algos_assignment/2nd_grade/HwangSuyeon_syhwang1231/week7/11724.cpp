// 11724: 연결 요소의 개수 (Silver 2)
#include <iostream>
#include <vector>
#define MAX 1001
using namespace std;

int n,m;  // n:정점 m:간선
vector<int> graph[MAX];
bool visited[MAX];

void dfs(int start){
    visited[start] = true;
    for(int i=0;i<graph[start].size();i++){
        int next = graph[start][i];
        if(!visited[next])
            dfs(next);
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    int u,v;
    for(int i=0;i<m;i++){
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    int cnt = 0;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            dfs(i);
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}
