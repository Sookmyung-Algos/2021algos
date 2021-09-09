#include<iostream>
#include<vector>
#include<queue>
#define MAX 1e9

using namespace std;

int m, n;
int dis[1001][1001];
int adj[1001][1001];
int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
int visit[1001][1001];

void dijkstra(int a, int b) {
	fill(&dis[0][0], &dis[1000][1001], MAX);
	priority_queue<pair<int, pair<int,int>>> pq;

	if (adj[a][b] != -1) {
		dis[a][b] = adj[a][b];
		pq.push({ dis[a][b], {a,b} });
	}

	while (!pq.empty()) {
		int c = -pq.top().first;	
		int x = pq.top().second.first;	
		int y = pq.top().second.second;

		pq.pop();
		if (c > dis[x][y])continue;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];

			if (nx >= 0 && ny >= 0 && nx < m && ny < n && !visit[nx][ny]) {
				int cost = adj[nx][ny];
				if (cost != -1) {
					if (dis[nx][ny] >= dis[x][y] + cost) {
						dis[nx][ny] = dis[x][y] + cost;
						pq.push({ -dis[nx][ny], {nx,ny} });
					}
				}
			}
		}
		visit[x][y] = true;
	}
}

int main() {
	cin >> m >> n;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> adj[i][j];
		}
	}

	dijkstra(0, 0);

	if (dis[m-1][n-1] == MAX)
		cout << -1;
	else
		cout << dis[m-1][n-1];

	return 0;
}