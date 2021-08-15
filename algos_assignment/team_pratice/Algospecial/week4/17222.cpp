#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int n, m, sep_cap[202], capacity[202][202] = {0};
	scanf("%d%d", &n, &m);
	int s = n + m + 1, e = 0;
	vector<int> edge[202];
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &sep_cap[i]);
		edge[i].push_back(e);
		edge[e].push_back(i);
		capacity[i][e] = 2147483647; // MAX
	}
	for (int i = n + 1; i <= n + m; ++i) {
		scanf("%d", &sep_cap[i]);
		edge[s].push_back(i);
		edge[i].push_back(s);
		capacity[s][i] = sep_cap[i];
	}
	for (int i = n + 1; i <= n + m; ++i) {
		int k;
		scanf("%d", &k);
		while (k--) {
			int j;
			scanf("%d", &j);
			edge[i].push_back(j);
			edge[j].push_back(i);
			capacity[i][j] = sep_cap[j];
		}
	}
	int ans = 0;
	while (true) {
		queue<int> q;
		q.push(s);
		int parent[201] = {0};
		while (!q.empty()) {
			int cur = q.front(); q.pop();
			for (auto i: edge[cur]) {
				if (parent[i] || capacity[cur][i] == 0) continue;
				parent[i] = cur;
				q.push(i);
				if (i == e) break;
			}
			if (parent[e]) break;
		}
		if (!parent[e]) break;
		int flow = 2147483647;
		for (int i = e; i != s; i = parent[i])
			flow = min(flow, capacity[parent[i]][i]);
		for (int i = e; i != s; i = parent[i]) {
			capacity[parent[i]][i] -= flow;
			capacity[i][parent[i]] += flow;
		}
		ans += flow;
	}
	printf("%d", ans);
	return 0;
}
