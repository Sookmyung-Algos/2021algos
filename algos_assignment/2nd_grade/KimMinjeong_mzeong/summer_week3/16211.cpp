#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define V 200001
#define MAX 2000000000

int baekchaewon[V], follower[V];
vector<pair<int, int>> adj[V];

void dijkstra(int S, int dis[]) {
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

	int n, m, k; cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int a, b, t; cin >> a >> b >> t;
		adj[a].push_back({ b, t });
		adj[b].push_back({ a, t });
	}

	queue<int> q; // 추종자들이 사는 지점의 번호 저장
	bool ans[V]; fill(ans, ans + n + 1, true);
	int cnt = n - 1; // 집이 될 수 있는 지점이 하나도 없을 경우를 찾기 위함
	for (int i = 0; i < k; i++) {
		int p; cin >> p;
		q.push(p);
	}

	dijkstra(1, baekchaewon);
	while(!q.empty()) {
		int num = q.front(); q.pop();
		dijkstra(num, follower);
		for (int i = 2; i <= n; i++) {
			if (ans[i] == false) continue;
			if (baekchaewon[i] >= follower[i]) {
				ans[i] = false; 
				cnt--;
			}
		}
	}
	
	if (cnt == 0) cout << 0;
	else {
		for (int i = 2; i <= n; i++) {
			if (ans[i]) cout << i << " ";
		}
	}
}
