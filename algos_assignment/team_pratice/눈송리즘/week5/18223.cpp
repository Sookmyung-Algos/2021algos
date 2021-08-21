#include <iostream>
#include <queue>
#include <vector>
#define MAX 987654321
using namespace std;

vector<pair<int, int>> adj[5001];
int dis[5001], v, e, p;

void dijkstra(int s) {
	fill(dis, dis + v + 1, MAX);
	priority_queue<pair<int, int>> pq;
	dis[s] = 0;
	pq.push({ 0,s });
	while (!pq.empty()) {
		int d = -pq.top().first;
		int u = pq.top().second;
		pq.pop();
		if (d > dis[u]) continue;
		for (int i = 0; i < adj[u].size(); i++) {
			int v = adj[u][i].first; //다음 정점
			int c = adj[u][i].second; //가중치
			if (dis[v] > dis[u] + c) {
				dis[v] = dis[u] + c;
				pq.push({ -dis[v],v });
			}
		}
	}
}

int main() {
	cin >> v >> e >> p;
	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ b,c });
		adj[b].push_back({ a,c });
	}
	dijkstra(1);
	int ans = dis[v];
	int a = dis[p];
	dijkstra(p);
	if (ans == a + dis[v]) {
		cout << "SAVE HIM";
	}
	else cout << "GOOD BYE";
}
