#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 2147483647
typedef pair<int, int> P;

int main() {
	int n, m, x;
	vector<P> edge1[1001], edge2[1001];
	scanf("%d%d%d", &n, &m, &x);
	while (m--) {
		int s, e, w;
		scanf("%d%d%d", &s, &e, &w);
		edge1[e].push_back({s, w});
		edge2[s].push_back({e, w});
	}
	priority_queue<P, vector<P>, greater<>> q;
	q.push({0, x});
	int dist1[1001], dist2[1001];
	for (int i = 1; i <= n; ++i) {
		dist1[i] = dist2[i] = MAX;
	}
	dist1[x] = dist2[x] = 0;
	while (!q.empty()) {
		int cur = q.top().second, d = q.top().first; q.pop();
		for (auto i: edge1[cur]) {
			int next_node = i.first, next_d = i.second;
			if (dist1[next_node] <= d + next_d)
				continue;
			dist1[next_node] = d + next_d;
			q.push({d + next_d, next_node});
		}
	}
	q.push({0, x});
	while (!q.empty()) {
		int cur = q.top().second, d = q.top().first; q.pop();
		for (auto i: edge2[cur]) {
			int next_node = i.first, next_d = i.second;
			if (dist2[next_node] <= d + next_d)
				continue;
			dist2[next_node] = d + next_d;
			q.push({d + next_d, next_node});
		}
	}
	int max = 0, max_i = x;
	for (int i = 1; i <= n; ++i) {
		if (dist1[i] + dist2[i] > max){
			max = dist1[i] + dist2[i];
			max_i = i;
		}
	}
	printf("%d", max);
	return 0;
}
