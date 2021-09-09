#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int n, m, capacity[605][605] = {0}, cost[605][605] = {0};
		scanf("%d%d", &n, &m);
		int s = 0, e = 2 * n + 1;
		int src = 2 * n + 2, sink = 2 * n + 3;
		vector<int> edge[605];
		for (int i = 1; i <= n; ++i) {
			edge[s].push_back(i);
			edge[i].push_back(s);
			capacity[s][i] = 1;
			edge[i].push_back(i + n);
			edge[i + n].push_back(i);
			capacity[i][i + n] = 1;
			cost[i][i + n] = -1;
			cost[i + n][i] = 1;
			edge[i + n].push_back(e);
			edge[e].push_back(i + n);
			capacity[i + n][e] = 1;
		}
		while (m--) {
			int a, b;
			scanf("%d%d", &a, &b);
			edge[a + n].push_back(b);
			edge[b].push_back(a + n);
			capacity[a + n][b] = 1;
		}
		edge[src].push_back(s);
		edge[s].push_back(src);
		capacity[src][s] = 2;
		edge[e].push_back(sink);
		edge[sink].push_back(e);
		capacity[e][sink] = 2;
		int ans = 0;
		while (true) {
			queue<int> q;
			q.push(src);
			int parent[605] = {0}, dist[605];
			for (int i = 0; i < 605; ++i) dist[i] = 2147483647; // MAX
			bool inQ[605] = {false};
			dist[src] = 0;
			inQ[src] = true;
			while (!q.empty()) {
				int cur = q.front(); q.pop(); inQ[cur] = false;
				// cout << cur << endl;
				for (auto i: edge[cur]) {
					if (capacity[cur][i] <= 0) continue;
					if (dist[i] <= dist[cur] + cost[cur][i]) continue;
					dist[i] = dist[cur] + cost[cur][i];
					parent[i] = cur;
					if (!inQ[i]) {
						q.push(i);
						inQ[i] = true;
					}
				}
			}
			if (!parent[sink]) break;
			int flow = 2147483647;
			for (int i = sink; i != src; i = parent[i])
				flow = min(flow, capacity[parent[i]][i]);
			for (int i = sink; i != src; i = parent[i]) {
				ans += flow * cost[parent[i]][i];
				capacity[parent[i]][i] -= flow;
				capacity[i][parent[i]] += flow;
			}
		}
		printf("%d\n", -ans);
	}
	return 0;
}
