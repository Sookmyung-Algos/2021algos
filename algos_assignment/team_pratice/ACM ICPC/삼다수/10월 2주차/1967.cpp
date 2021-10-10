#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int n;
int deepest = 0;
int radius = 0;
vector <pair<int, int>> v[10001];
bool visited[10001] = {false, };


void dfs(int x, int c){

	if(visited[x] == true){
		return;
	}

	visited[x] = true;

	if(radius < c){
		radius = c;
		deepest = x;
	}

	for(int i = 0; i < v[x].size(); i++){
		int cost = v[x][i].second + c;
		dfs(v[x][i].first, cost);
	}
}

int main() {
  cin>>n;

  for(int i = 0; i < n-1; i++){
	  int a, b, c;
	  cin>>a>>b>>c;
	  v[a].push_back({b, c});
	  v[b].push_back({a, c});
  }

  dfs(1, 0);

  memset(visited, false, sizeof(visited));
  radius = 0;

  dfs(deepest, 0);

  cout<<radius;
  return 0;

}
