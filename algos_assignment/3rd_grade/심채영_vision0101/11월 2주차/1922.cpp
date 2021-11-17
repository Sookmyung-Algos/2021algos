#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;

const int MAX = 1000 + 1;
int N, M;
vector<pair<int, int>> graph[MAX];

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
bool visited [MAX];


int main() {
  cin >> N >> M;

  for(int i=0; i<M; i++) {
    int a, b, c;
    cin >> a >> b >> c;

    graph[a].push_back({c, b});
    graph[b].push_back({c, a});
  }

  pq.push({0, 1});
  int result = 0; 
  while (!pq.empty()) {
    int cost = pq.top().first;
    int vertex = pq.top().second;
    pq.pop();

    if(!visited[vertex]) {
      visited[vertex] = true;
      result += cost;

      for(int i=0; i<graph[vertex].size(); i++) {
        int nextCost = graph[vertex][i].first;
        int nextVertex = graph[vertex][i].second;

        if(!visited[nextVertex]) {
          pq.push({nextCost, nextVertex});
        }
      }
    }
  }
  cout << result << "\n";
  return 0;
} 
