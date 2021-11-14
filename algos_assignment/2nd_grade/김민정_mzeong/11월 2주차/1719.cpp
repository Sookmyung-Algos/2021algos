#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 201
#define INF 1e9

int n, m;
int dist[MAX];
int graph[MAX][MAX];
vector<pair<int, int>> edge[MAX];

void dijkstra(int s) {
	for (int i = 1; i <= n; i++) dist[i] = INF;
	priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

	pq.push({ 0, {s,s} });
	dist[s] = 0;
	while (!pq.empty()) {
		int cost = pq.top().first;
		int node = pq.top().second.first;
		int fn = pq.top().second.second;
		pq.pop();

		for (int i = 0; i < edge[node].size(); i++) {
			int next = edge[node][i].first;
			int nextcost = edge[node][i].second;

			if (dist[next] > cost + nextcost) {
				dist[next] = cost + nextcost;
				if (fn == s) graph[s][next] = next;
				else graph[s][next] = fn;
				pq.push({ dist[next], {next, graph[s][next]} });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int s, e, t;
		cin >> s >> e >> t;
		edge[s].push_back({ e, t });
		edge[e].push_back({ s, t });
	}

	for (int i = 1; i <= n; i++) {
		dijkstra(i);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) {
				cout << "- ";
				continue;
			}
			cout << graph[i][j] << " ";
		}
		cout << "\n";
	}
}
