#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int s = 1002, e = 1003;
	int n, capacity[1004][1004] = {0}, flow[1004][1004] = {0};
	scanf("%d", &n);
	vector<int> edge[1004];
	int row_sum = 0, col_sum = 0;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &capacity[s][i]);
		edge[s].push_back(i);
		edge[i].push_back(s);
		row_sum += capacity[s][i];
	}
	for (int i = n + 1; i <= 2 * n; ++i) {
		scanf("%d", &capacity[i][e]);
		edge[i].push_back(e);
		edge[e].push_back(i);
		col_sum += capacity[i][e];
	}
	if (row_sum != col_sum) {
		printf("-1");
		return 0;
	}
	for (int i = 1; i <= n; ++i)
		for (int j = n + 1; j <= 2 * n; ++j) {
			edge[i].push_back(j);
			edge[j].push_back(i);
			capacity[i][j] = 1;
		}
	int ans = 0;
	while (true) {
		queue<int> q;
		q.push(s);
		int parent[1004] = {0};
		while (!q.empty()) {
			int cur = q.front(); q.pop();
			for (auto i: edge[cur]) {
				if (parent[i] || capacity[cur][i] <= flow[cur][i]) continue;
				parent[i] = cur;
				q.push(i);
				if (i == e) break;
			}
			if (parent[e]) break;
		}
		if (!parent[e]) break;
		for (int i = e; i != s; i = parent[i]) {
			flow[parent[i]][i] += 1;
			flow[i][parent[i]] -= 1;
		}
		ans += 1;
	}
	if (ans != row_sum) {
		printf("-1");
		return 0;
	}
	printf("1\n");
	for (int i = 1; i <= n; ++i) {
		for (int j = n + 1; j <= 2 * n; ++j)
			printf("%d", flow[i][j]);
		printf("\n");
	}
	return 0;
}
