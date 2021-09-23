#include <iostream>
#include <vector>
using namespace std;

int n, m, v, u, answer;
vector<vector<int> > adj;
vector<int> visited;

void solve(int vertex) {
    visited[vertex] = 1;

    for(int i = 0; i < adj[vertex].size(); i++) {
        int next = adj[vertex][i];
        if (!visited[next]) solve(next);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    visited.resize(n+1);
    adj.resize(n+1, vector<int>());

    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    for(int i = 1; i <= n; i++) {
        if (!visited[i]) {
            solve(i);
            answer++;
        }
    }
    cout << answer << "\n";
    return 0;
}
