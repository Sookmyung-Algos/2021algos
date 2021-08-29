#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 987654321
using namespace std;

int v, e, dis[20001], s;
vector<pair<int, int>> adj[20001];

void dijkstra(int s) {
	fill(dis, dis + v + 1, MAX);
	priority_queue<pair<int, int>> pq;
	dis[s] = 0;
	pq.push({ 0,s });
	while (!pq.empty()) {
		int d = -pq.top().first; //시작지점으로부터의 거리
		int u = pq.top().second; //현재 정점
		pq.pop();
		if (d > dis[u])continue;
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
	cin >> v >> e;
	cin >> s;
	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ b,c });
	}
	dijkstra(s);
	for (int i = 1; i <= v; i++) {
		if (dis[i] == MAX) cout << "INF\n";
		else cout << dis[i] << '\n';
	}
}
