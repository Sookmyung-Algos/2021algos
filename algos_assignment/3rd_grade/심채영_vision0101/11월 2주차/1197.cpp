#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<pair<int, int>>> edge;
priority_queue<pair<int, int>, vector<pair<int, int>>,greater<int>> pq;
bool visited[10001];
int v, e, c, k;
int DT[10001];

void prim(int v) {
  visited[v] = true;

  for(auto u : edge[v]) {
    if(!visited[u.second]) {
      pq.push({u.first, u.second});
    }
  }

  while(!pq.empty()) {
    auto w = pq.top();
    pq.pop();
    if(!visited[w.second]) {
      k += w.first;
      prim(w.second);
      return;
    }
  }
}

int main() {
  cin >> v >> e;
  edge.resize(v + 1);
  int x, y, z;
  for (int i=0; i<e; i++) {
    cin >> x >> y >> z;
    edge[x].push_back({z, y});
    edge[y].push_back({z, x});
  }
  prim(1);
  cout << k << endl;

  return 0;
} 
