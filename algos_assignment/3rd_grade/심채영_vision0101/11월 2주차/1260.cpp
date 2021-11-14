#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(int start, vector<int> graph[], bool check[]) {
  check[start] = true;
  cout << start << " ";

  for(int i = 0; i < graph[start].size(); i++) {
    int next = graph[start][i];
    if(check[next] == false) {
      dfs(next, graph, check);
    }
  }
}
int main() {
  int n, m, start;
  cin >> n >> m >> start;

  vector<int> graph[n+1];
  bool check [n+1];
  fill(check, check+n+1, false);

  for(int i=0; i<m; i++) {
    int u, v;
    cin >> u >> v;

    graph[u].push_back(v);
    graph[v].push_back(v);
  }

  for(int i=1; i<=n; i++) {
    sort(graph[i].begin(), graph[i].end());
  }

  dfs(start, graph, check);
  cout << endl;

  return 0;
} 
