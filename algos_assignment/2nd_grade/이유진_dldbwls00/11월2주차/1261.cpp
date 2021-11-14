#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 1e9
#define MAX 110

int n, m;
int dist[MAX][MAX];
int map[MAX][MAX];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 2, -2 };

void dijkstra() {
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

	pq.push({ 0, {1, 1} });

	while (!pq.empty()) {
		int cost = pq.top().first;
		int nodex = pq.top().second.second;
		int nodey = pq.top().second.first;

		pq.pop();

		for (int i = 0; i < 4; i++) {
			int nextx = nodex + dx[i];
			int nexty = nodey + dy[i];

			if (nextx > m || nexty > n || nextx <= 0 || nexty <= 0)	continue;

			int nextcost = cost + map[nexty][nextx];

			if (dist[nexty][nextx] > nextcost) {
				dist[nexty][nextx] = nextcost;
				pq.push({ nextcost, {nexty, nextx} });
			}
		}
	}
}
int main() {
	cin >> m >> n;
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++)	dist[i][j] = INF; //초기화
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)	scanf("%ld", &map[i][j]);
	}
	dist[1][1] = 0;
	dijkstra();
	cout << dist[n][m];
	return 0;
}
