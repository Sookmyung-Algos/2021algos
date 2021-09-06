#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 100000

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t; cin >> t;
	while (t--) {
		vector<pair<int, int>> adj[101];
		vector<int> room;
		int ans, mn = MAX * 100, dis[101];

		int n, m; cin >> n >> m;
		for (int i = 0; i < m; i++) {
			int a, b, c; cin >> a >> b >> c;
			adj[a].push_back({ b, c });
			adj[b].push_back({ a, c });
		}
		int k; cin >> k;
		for (int i = 0; i < k; i++) {
			int num; cin >> num;
			room.push_back(num);
		}

		for (int i = 1; i <= n; i++) {
			fill(dis, dis + n + 1, MAX);
			priority_queue<pair<int, int>> pq;
			dis[i] = 0;
			pq.push({ 0, i });
			while (!pq.empty()) {
				int d = -pq.top().first;
				int u = pq.top().second; pq.pop();
				if (d > dis[u]) continue;
				for (int j = 0; j < adj[u].size(); j++) {
					int v = adj[u][j].first;
					int c = adj[u][j].second;
					if (dis[v] > dis[u] + c) {
						dis[v] = dis[u] + c;
						pq.push({ -dis[v], v });
					}
				}
			}
			int total = 0;
			for (int j = 0; j < room.size(); j++) total += dis[room[j]];
			if (total < mn) {
				mn = total;
				ans = i;
			}
		}
		cout << ans << "\n";
	}
}
