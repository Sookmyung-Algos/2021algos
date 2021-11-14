#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 1e9
using namespace std;

int n, m, x;
vector<pair<int, int>> v[1001];
int dist[1001];
int sum[1001];

int dijkstra(int start) {
	for (int i = 1; i <= n; i++) dist[i] = INF;
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, start });
	dist[start] = 0;

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (dist[cur] < cost) continue;
		
		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i].second;
			int nc = cost + v[cur][i].first;
			if (dist[next] > nc) {
				dist[next] = nc;
				pq.push({ -nc, next });
			}
		}
	}
	if (start == x) {
		for (int i = 1; i <= n; i++) sum[i] += dist[i];
	}
	return dist[x];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m >> x;

	for (int i = 0, a, b, c; i < m; i++) {
		cin >> a >> b >> c;
		v[a].push_back({ c, b });
	}

	for (int i = 1; i <= n; i++) sum[i] += dijkstra(i);;

	int ans = 0;
	for (int i = 1; i <= n; i++)
		ans = max(ans, sum[i]);

	cout << ans << '\n';

	return 0;
}
