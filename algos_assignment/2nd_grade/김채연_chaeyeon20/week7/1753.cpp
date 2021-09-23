#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pii;

int V, E, K;
vector<pii> tree[20001];
int dist[20001];

void dijkstra(int start) {
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	dist[start] = 0;
	pq.push({ 0, start });
	while (!pq.empty()) {
		auto [d, u] = pq.top(); pq.pop();
		if (d > dist[u]) continue;
		for (auto [c, v] : tree[u]) {
			if (dist[v] > dist[u] + c) {
				dist[v] = dist[u] + c;
				pq.push({ dist[v], v });
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	fill(dist, dist + 20001, 1e9);
	cin >> V >> E >> K;
	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		tree[u].push_back({ w, v });
	}
	dijkstra(K);
	for (int i = 1; i <= V; i++) {
		if (dist[i] == 1e9) cout << "INF\n";
		else cout << dist[i] << '\n';
	}
}
