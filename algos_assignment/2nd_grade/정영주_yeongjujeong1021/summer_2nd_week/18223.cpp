#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 50000001 // 5000(n) * 10000(c)
using namespace std;

vector<pair<int, int>> v[5001];
priority_queue<pair<int, int>> pq;
int n, m, p, cost[5001];

int dijkstra(int st, int en) {
	fill(cost, cost + n + 1, INF);
	cost[st] = 0;
	pq.push({ 0, st });

	while (!pq.empty()) {
		int cc = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (cc > cost[cur]) continue;

		for (int i = 0; i < v[cur].size(); i++) {
			int nc = cc + v[cur][i].first;
			int next = v[cur][i].second;
			if (nc < cost[next]) {
				cost[next] = nc;
				pq.push({ -nc, next });
			}
		}
	}

	return cost[en];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m >> p;

	for (int i = 0, a, b, c; i < m; i++) {
		cin >> a >> b >> c;
		v[a].push_back({ c, b });
		v[b].push_back({ c, a });
	}

	if (dijkstra(1, n) >= dijkstra(1, p) + dijkstra(p, n))
		cout << "SAVE HIM\n";
	else cout << "GOOD BYE\n";

	
	return 0;
}
