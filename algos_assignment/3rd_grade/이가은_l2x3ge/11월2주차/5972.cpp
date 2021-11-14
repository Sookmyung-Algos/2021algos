#include<iostream>
#include<vector>
#include<queue>
#define MAX 1e9
using namespace std;
void dijkstra(int s);

int V, E;
int dis[100005];
vector<pair<int, int>> adj[100005];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> V >> E;
	
	for (int i = 0;i < E;i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ b,c });
		adj[b].push_back({ a,c });
	}
	dijkstra(1);
	cout << dis[V] << "\n";
	
	return 0;
}

void dijkstra(int s) {
	fill(dis, dis + V + 1, MAX);
	priority_queue<pair<int, int>> pq;//{cost, start}
	dis[s] = 0;
	pq.push({ 0,s });
	while (!pq.empty()) {
		int d = -pq.top().first; //cost
		int u = pq.top().second; //from정점
		pq.pop();

		if (d > dis[u]) //cost가 (시작~from)보다 더 크면 가지 않는다
			continue;
		for (int i = 0; i < adj[u].size();i++) {
			int v = adj[u][i].first; //to정점
			int c = adj[u][i].second; //(from~to cost)
			if (dis[v] > dis[u] + c) {
				dis[v] = dis[u] + c;
				pq.push({ -dis[v], v });
			}
		}
	}
}
