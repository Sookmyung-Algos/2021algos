#include <iostream>
#include <queue>
#include <vector>
#define MAX 987654321
using namespace std;

int dis[1001], n, m;
vector < pair<int,int>> adj[1001];

void dijkstra(int s) {
	fill(dis, dis + n + 1, MAX);
	priority_queue<pair<int, int>> pq;
	dis[s] = 0;
	pq.push({ 0,s });
	while (!pq.empty()) {
		int d = -pq.top().first; //시작지점부터의 거리
		int u = pq.top().second; //현재 정점
		pq.pop();
		if (d > dis[u]) continue;
		for (int i = 0; i < adj[u].size(); i++) {
			int v = adj[u][i].first; //다음 정점
			int c = adj[u][i].second; //가중치
			if (dis[v] > dis[u] + c) { //다음 정점 > 현재 정점까지 + 가중치 이면
				dis[v] = dis[u] + c;
				pq.push({ -dis[v],v });
			}
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ b,c });
	}
	int x, y;
	cin >> x >> y;
	dijkstra(x);
	cout << dis[y];
}
