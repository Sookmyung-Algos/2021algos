#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 987654321
using namespace std;

int n, e;
int dis[801];
vector<pair<int, int>> adj[801];

void dijkstra(int s) {
	fill(dis, dis + n+1, MAX);
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
	cin >> n >> e;
	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back(make_pair(b, c));
		adj[b].push_back(make_pair(a, c));
	}
	int v1, v2;
	long long dis_v1, dis_v2, v1_n, v2_n, v12;
	cin >> v1 >> v2;
	dijkstra(1);
	dis_v1 = dis[v1];
	dis_v2 = dis[v2];
	dijkstra(v1);
	v1_n = dis[n];
	v12 = dis[v2];
	dijkstra(v2);
	v2_n = dis[n];
	long long ans1 = dis_v1 + v12 + v2_n;
	long long ans2 = dis_v2 + v12 + v1_n;
	if (ans1 >= MAX && ans2 >= MAX) cout << "-1";
	else  cout<<min(ans1, ans2);
}
