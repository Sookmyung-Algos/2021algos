// 1753.cpp (G5)

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 222222
using namespace std;

vector<pair<int, int>> v[20001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int cost[20001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m, k; // k: 시작 정점의 번호
	cin >> n >> m >> k; // 1 <= n <= 20,000 1 <= m <= 300,000

	for (int i = 0, a, b, c; i < m; i++) {
		cin >> a >> b >> c;
		v[a].push_back({ c, b });
	}

	for (int i = 1; i <= n; i++) cost[i] = INF;

	pq.push({ 0, k });
	cost[k] = 0;

	while (!pq.empty()) {
		int c = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (c > cost[cur]) continue;

		for (int i = 0; i < v[cur].size(); i++) {
			int nc = v[cur][i].first + c;
			int next = v[cur][i].second;

			if (nc < cost[next]) {
				cost[next] = nc;
				pq.push({ nc, next });
			}

		}
	}

	for (int i = 1; i <= n; i++) {
		if (cost[i] == INF) cout << "INF\n";
		else cout << cost[i] << '\n';
	}

	return 0;
}
