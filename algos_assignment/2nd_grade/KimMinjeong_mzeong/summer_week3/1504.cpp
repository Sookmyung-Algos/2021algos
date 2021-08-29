#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int V = 800 + 1;
const int MAX = 1000 * 800;

int dis[V];
vector<pair<int, int>> adj[V];
long long ans[3]; // ans[1]: 1 - v1 - v2 - n, ans[2]: 1 - v2 - v1 - n

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

	int n, e; cin >> n >> e;
	for (int i = 0; i < e; i++) {
		int a, b, c; cin >> a >> b >> c;
		adj[a].push_back({ b, c });
		adj[b].push_back({ a, c });
	}
	int v1, v2; cin >> v1 >> v2;

	dijkstra(v1);
	ans[1] += dis[1] + dis[v2];
	ans[2] += dis[n];
	dijkstra(v2);
	ans[1] += dis[n];
	ans[2] += dis[1] + dis[v1];

	if (ans[1] >= MAX && ans[2] >= MAX) cout << -1;
	else cout << (ans[1] < ans[2] ? ans[1] : ans[2]);
}
