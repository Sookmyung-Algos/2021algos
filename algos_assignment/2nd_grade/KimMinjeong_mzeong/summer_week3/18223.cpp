#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 50000000
#define V 5001

int dis[V];
vector<pair<int, int>> adj[V];

void dijkstra(int S) {
	fill(dis, dis + V, MAX);
	priority_queue<pair<int, int>> pq;
	dis[S] = 0;
	pq.push({ 0, S });
	while (!pq.empty()) {
		int d = -pq.top().first;
		int u = pq.top().second;
		pq.pop();
		if (d > dis[u]) continue;
		for (int i = 0; i < adj[u].size(); i++) {
			int v = adj[u][i].first;
			int c = adj[u][i].second;
			if (dis[v] > dis[u] + c) {
				dis[v] = dis[u] + c;
				pq.push({ -dis[v], v });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int v, e, p; cin >> v >> e >> p;
	for (int i = 0; i < e; i++) {
		int a, b, c; cin >> a >> b >> c;
		adj[a].push_back({ b, c });
		adj[b].push_back({ a, c });
	}

	long long min = 0;
	dijkstra(1); min += dis[v];
	dijkstra(p);
	if (min < dis[1] + dis[v]) cout << "GOOD BYE";
	else cout << "SAVE HIM";
}
