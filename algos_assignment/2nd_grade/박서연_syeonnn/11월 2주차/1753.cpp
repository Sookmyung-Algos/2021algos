// 1753 최단경로

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int dis[20001];	// 시작점에서 다른 정점으로의 최단거리 저장할 배열
const int INF = 1e9;
vector<pair<int, int> > line[20001];	// 간선 나타내는 벡터배열 (가중치,정점 번호 저장) 

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int V, E, K;	// 정점 개수, 간선 개수, 시작 정점 번호

	cin >> V >> E >> K;

	for (int i = 0; i < E; i++) {
		int u, v, w;	// u에서 v로 가는 가중치가 w인 간선
		cin >> u >> v >> w;
		line[u].push_back({w, v});	// 가중치,정점 번호 순으로 저장
	}

	fill(dis, dis + V + 1, INF);	// 배열 초기화
	dis[K] = 0;	// 시작점에서 시작점까지 거리 = 0
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq; // < 자료형, 컨테이너, 비교함수 > , <시작점으로부터의 거리, 해당 정점 번호> 저장

	pq.push(make_pair(dis[K], K));	// 시작점 추가

	while (!pq.empty()) {

		// 내림차순 정렬했으므로 가중치 가장 작은 간선이 나옴
		int d = pq.top().first;
		int n = pq.top().second;
		pq.pop();

		if (dis[n] != d)
			continue;

		for (int i = 0; i < line[n].size(); i++) {	// 인접리스트에 대해

			int dd = line[n][i].first;
			int nn = line[n][i].second;

			if (dis[nn] > d + dd) {	// 현재 최단거리보다 그 값이 작으면
				dis[nn] = d + dd; // 최단거리 갱신
				pq.push({ dis[nn], nn });
			}
		}
	}
	for (int i = 1; i <= V; i++) {
		if (dis[i] == INF)	// 경로 존재하지 않는 경우
			cout << "INF\n";
		else
			cout << dis[i] << "\n";
	}

	return 0;
}
