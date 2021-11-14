#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 20001
#define INF 1e9

using namespace std;

int v, e, k, a, b, w;
int dist[MAX]; // index 번째 정점까지의 최단경로의 경로값
vector<pair<int, int>> edge[MAX]; // index 번째 정점으로의 간선과 가중치 벡터

void dijkstra() {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, k }); // 시작정점의 경로값과 index를 pq에 push
	dist[k] = 0; // 시작정점의 경로값은 0

	while (!pq.empty()) {
		int cost = pq.top().first;
		int node = pq.top().second;

		pq.pop();

		for (int i = 0; i < edge[node].size(); i++) {
			int next = edge[node][i].first;
			int next_cost =edge[node][i].second;

			// 최단거리 갱신
			if (dist[next] > cost+next_cost) {
				dist[next] = cost+next_cost;
				pq.push({ dist[next], next });
			}
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> v >> e >> k;

	for (int i = 0; i < e; i++) {
		cin >> a >> b >> w;
		edge[a].push_back({ b,w });
	}

	for (int i = 1; i <= v; i++) { // 초기화
		dist[i] = INF;
	}

	dijkstra();

	for (int i = 1; i <= v; i++) {
		if (dist[i] == INF) { // 경로가 존재하지 않은 경우
			cout << "INF\n";
		} 
		else { // 최단 경로 출력
			cout << dist[i] << endl;
		}
	}
}
