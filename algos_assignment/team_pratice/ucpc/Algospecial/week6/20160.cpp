#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

#define INF 1LL<<60

typedef pair<long long, int> P;

int main() {
	int v, e;
	scanf("%d%d", &v, &e);
	vector<pair<int,int>> edge[10001];
	while (e--) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		edge[u].push_back({v, w});
		edge[v].push_back({u, w});
	}
	int spot[11];
	for (int i = 0; i < 10; ++i)
		scanf("%d", &spot[i + 1]);
	int start; scanf("%d", &start); // 내가 시작하는 정점 번호
	long long spot_dist[11]; // 각 지점으로 야구르트 가는 거리
	spot_dist[1] = 0; // 1번 지점
	long long last = spot[1], last_dist = 0; // 마지막까지 거리.
	for (int cur_spot = 2; cur_spot <= 10; ++cur_spot) {
		priority_queue<P, vector<P>, greater<>> q; // 거리, 지점
		q.push({0, last});
		long long dist[10001];
		for (int i = 1; i <= v; ++i) dist[i] = INF;
		dist[last] = 0;
		while (!q.empty()) {
			int cur = q.top().second, cur_dist = q.top().first; q.pop();
			if (cur_dist > dist[cur])
				continue;
			if (cur == spot[cur_spot]) break; //
			for (auto i: edge[cur]) {
				if (dist[i.first] <= cur_dist + i.second) continue;
				dist[i.first] = cur_dist + i.second;
				q.push({cur_dist + i.second, i.first});
			}
		}
		if (dist[spot[cur_spot]] == INF) spot_dist[cur_spot] = INF;
		else {
			last = spot[cur_spot];
			last_dist = spot_dist[cur_spot] = last_dist + dist[spot[cur_spot]];
		}
	}
	
	priority_queue<P, vector<P>, greater<>> q; // 거리, 지점
	q.push({0, start});
	long long dist[10001];
	for (int i = 1; i <= v; ++i) dist[i] = INF;
	dist[start] = 0;
	while (!q.empty()) {
		int cur = q.top().second, cur_dist = q.top().first; q.pop();
		if (cur_dist > dist[cur])
			continue;
		for (auto i: edge[cur]) {
			if (dist[i.first] <= cur_dist + i.second) continue;
			dist[i.first] = cur_dist + i.second;
			q.push({cur_dist + i.second, i.first});
		}
	}
	vector<int> ans;
	for (int i = 1; i <= 10; ++i) {
		if (spot_dist[i] != INF && dist[spot[i]] <= spot_dist[i])
			ans.push_back(spot[i]);
	}
	if (ans.size()) {
		sort(ans.begin(), ans.end());
		// for (auto i: ans) printf("%d ", i); cout << endl;
		printf("%d", ans[0]);
	}
	else {
		printf("-1");
	}
	return 0;
}
