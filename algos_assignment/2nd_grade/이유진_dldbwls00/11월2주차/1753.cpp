#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 1e9
#define MAX 20001

int visited[MAX];
int dist[MAX];
vector<pair<int, int>> edge[MAX];
int v, e, k;

void dijkstra() {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	pq.push({ 0,k });
	dist[k] = 0;

	while (!pq.empty()) {
		int cost = pq.top().first;
		int node = pq.top().second;

		pq.pop();

		for (int i = 0; i < edge[node].size(); i++) {
			int next = edge[node][i].first;
			int nextcost = edge[node][i].second;

			if (dist[next] > cost + nextcost) {
				dist[next] = cost + nextcost;
				pq.push({ dist[next], next });
			}
		}
	}
}
int main() {
	cin >> v >> e >> k;
	for (int i = 0; i < e; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		edge[a].push_back({ b,w });
	}
	for (int i = 1; i <= v; i++)	dist[i] = INF;
	dijkstra();
	for (int i = 1; i <= v; i++) {
		if (dist[i] == INF)	cout << "INF\n";
		else  cout << dist[i] << "\n";
	}
	return 0;
}
