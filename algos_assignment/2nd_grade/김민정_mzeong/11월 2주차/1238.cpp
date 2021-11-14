#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX 10001
#define INF 1e9

int n, m, x;
int dist[MAX], go[MAX];
vector<pair<int, int>> edge[MAX];

int dijkstra(int s) {
	for (int i = 1; i <= n; i++) dist[i] = INF;
	priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

	pq.push({ 0, s });
	dist[s] = 0;
	while (!pq.empty()) {
		int cost = pq.top().first;
		int node = pq.top().second;
		pq.pop();

		for (int i = 0; i < edge[node].size(); i++) {
			int next = edge[node][i].first;
			int next_cost = edge[node][i].second;

			if (dist[next] > cost + next_cost) {
				dist[next] = cost + next_cost;
				pq.push({ dist[next], next });
			}
		}
	}
	return dist[x];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m >> x;
	for (int i = 0; i < m; i++) {
		int s, e, t;
		cin >> s >> e >> t;
		edge[s].push_back({ e, t });
	}

	for (int i = 1; i <= n; i++) {
		if (i == x) continue;
		go[i] = dijkstra(i);
	}
	dijkstra(x);

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (ans < go[i] + dist[i]) ans = go[i] + dist[i];
	}
	cout << ans;
}
