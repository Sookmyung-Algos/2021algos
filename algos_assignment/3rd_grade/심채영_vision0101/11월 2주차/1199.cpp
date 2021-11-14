#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 1000 + 1;
int N;
int DT[MAX];

int graph[7][7] {
  {0, 0, 0, 0, 0, 0, 0},
  {0, 0, 1, 0, 1, 1, 1},
  {0, 1, 0, 1, 1, 1, 0},
  {0, 0, 1, 0, 1, 0, 0},
  {0, 1, 1, 1, 0, 1, 0},
  {0, 1, 1, 0, 1, 0, 1},
  {0, 1, 0, 0, 0, 1, 0}
};

int degree[MAX];
vector<int> order;

void DFS(int node) {
  for(int i=1; i<=N; i++) {
    while (graph[node][i]) {
      graph[node][i]--;
      graph[i][node]--;
      DFS(i);
    }
  }
  order.push_back(node);
}

int main() {
  cin >> N;

  for(int i=1; i<=N; i++) {
    for(int j=1; j<=N; j++) {
      degree[i] += graph[i][j];
      degree[j] += graph[i][j];
    }
  }

  bool canEuler = true;
  for(int i=0; i<=N; i++) {
    degree[i] /= 2;
    if(degree[i] % 2 ){
      canEuler = false;
      break;
    }
  }

  if(canEuler){
    DFS(1);
    reverse(order.begin(), order.end());
    for(int i=0; i<order.size(); i++){
      cout << order[i] << " ";
    }
    cout << "\n";
  }
  else{
    cout << -1 << "\n";
  }
  return 0;
} 
