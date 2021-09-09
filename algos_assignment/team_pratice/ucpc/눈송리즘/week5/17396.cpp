#include <iostream>
#include <vector>
#include <queue>
#define MAX 10000000001
using namespace std;

vector<pair<int, int>> adj[100001];
long long dis[100001];
int as[100001], n, m;

void dijkstra(int s) {
	fill(dis, dis + n, MAX);
	priority_queue<pair<int, long long>> pq;
	dis[s] = 0;
	pq.push({ 0,s });
	while (!pq.empty()) {
		int d = -pq.top().first;
		int u = pq.top().second;
		pq.pop();
		if (d > dis[u]) continue;
		for (int i = 0; i < adj[u].size(); i++) {
			int v = adj[u][i].first;
			int c = adj[u][i].second;
			
			if( !(as[v] && v!=n-1) && (dis[v] > dis[u] + c)) {
				dis[v] = dis[u] + c;
				pq.push({ -dis[v],v });
			}
			
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> as[i];
	}
	for (int i = 0; i < m; i++) {
		int a, b, t;
		cin >> a >> b >> t;
		adj[a].push_back({ b,t });
		adj[b].push_back({ a,t });
	}
	dijkstra(0);
	if (dis[n-1] == MAX) cout << "-1";
	else cout << dis[n-1];
}
