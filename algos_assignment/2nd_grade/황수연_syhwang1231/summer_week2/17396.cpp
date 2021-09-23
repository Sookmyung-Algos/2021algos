// 17396 백도어 (Gold 5)
#include <iostream>
#include <vector>
#include <queue>
#define MAX 100000000000
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int N, M;

	cin >> N >> M;
	vector<int> canSee(N, 0);
	vector<vector<pair<int, int>>> graph(N);  // first: 연결된 정점 번호, second: 거리
	vector<bool> visited(N, false);

	for (int i = 0; i < N; i++) {
		cin >> canSee[i];
	}

	for (int i = 0; i < M; i++) {
		int a, b, t;
		cin >> a >> b >> t;
		graph[a].push_back({ t,b });
		graph[b].push_back({ t,a });
	}

	// 다익스트라
	vector<long long> dis(N, MAX);
	priority_queue<pair<long long, int>> pq;  // first: 거리, second: 정점
	dis[0] = 0;
	pq.push({ 0, 0 });

	while (!pq.empty()) {
		long long curD = -pq.top().first;
		int curV = pq.top().second;
		pq.pop();

		if (curD > dis[curV] || visited[curV]) continue;  // 이미 방문했거나 갱신 불필요한 경우 다음 반복
		if (canSee[curV] == 1) continue;  // 적의 시야에서 보이는 경우 다음 반복

		visited[curV] = true;
		for (int i = 0; i < graph[curV].size(); i++) {
			long long nextD = graph[curV][i].first;
			int nextV = graph[curV][i].second;
			if (dis[nextV] > dis[curV] + nextD) {
				dis[nextV] = dis[curV] + nextD;
				pq.push({ -dis[nextV],nextV });
			}
		}
	}

	if (dis[N-1] >= MAX)
		cout << "-1";
	else
		cout << dis[N-1];
	return 0;
}
