#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector <int> graph[32001];
int indegree[32001];
int n,m;

void topological(){
    queue<int> q;
    for (int i=1;i<=n;i++){
        if (!indegree[i]) q.push(i);
    }
    
    while (!q.empty()){
        int c = q.front();
        q.pop();
        cout << c << '\n';
        
        for (int i=0;i<graph[c].size();i++){
            indegree[graph[c][i]]--;
            if (!indegree[graph[c][i]]){
                q.push(graph[c][i]);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        indegree[b]++;
    }
    topological();
    
    return 0;
}
