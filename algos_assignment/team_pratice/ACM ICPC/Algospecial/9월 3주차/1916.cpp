#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define MAX 2147483647

typedef pair<int,int> P;

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	vector<pair<int,int>> edge[1001];
	while (m--) {
		int s, e, w;
		scanf("%d%d%d", &s, &e, &w);
		edge[s].push_back({e, w});
	}
	int start, end;
	scanf("%d%d", &start, &end);
	priority_queue<P, vector<P>, greater<>> q;
	q.push({0, start});
	int dist[1001];
	for (int i = 1; i <= n; ++i)
		dist[i] = MAX;
	dist[start] = 0;
	while (!q.empty()) {
		int d = q.top().first, cur = q.top().second; q.pop();
		if (d > dist[cur]) continue;
		for (auto i: edge[cur]) {
			int next_node = i.first, next_d = i.second;
			if (dist[next_node] <= d + next_d)
				continue;
			q.push({d + next_d, next_node});
			dist[next_node] = d + next_d;
		}
	}
	printf("%d", dist[end]);
	return 0;
}
