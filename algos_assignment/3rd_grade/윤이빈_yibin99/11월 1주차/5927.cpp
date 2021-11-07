#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<pair<int,int>> graph[50001];
int dist[50001];
void dijk(){
	fill(dist, dist+n+1, 0x7fffffff);
	priority_queue<pair<int,int>> pq;
	pq.push({0, 1});
	dist[1]=0;
	while(!pq.empty()){
		int d=-pq.top().first;
		int v=pq.top().second;
		pq.pop();
		if(d>dist[v]) continue;
		dist[v]=d;
		for(int i=0;i<graph[v].size();i++){
			if(dist[graph[v][i].second]>dist[v]+graph[v][i].first){
				pq.push({-(dist[v]+graph[v][i].first), graph[v][i].second});
			}
		}
	}
}

int main() {
	cin >> n >> m;
	for(int i=0;i<m;i++){
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({c, b});
		graph[b].push_back({c, a});
	}
	dijk();
	cout << dist[n];
}
