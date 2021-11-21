#include <iostream>
#include <vector>
using namespace std;
#define MAX 501
#define INF 2*1e9

int dist[MAX];
vector<pair<int, int>> edge[MAX];

// 방문한 정점에 대해서만 최단거리 갱신->오답
// 시작 정점으로부터 도달할 수 없는 음수 사이클을 못 찾기 때문
bool bellmanFord(int N) {
	bool cycle = false;
	dist[1] = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 0; k < edge[j].size(); k++) {
				int next = edge[j][k].first;
				int cost = edge[j][k].second;

				if (dist[next] > dist[j] + cost) {
					dist[next] = dist[j] + cost;
					if (i == N) cycle = true;
				}
			}
		}
	}
	return cycle;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int TC; cin >> TC;
	while (TC--) {
		int N, M, W;
		cin >> N >> M >> W;

		for (int i = 0; i <= N; i++) dist[i] = INF;
		for (int i = 0; i <= N; i++) edge[i].clear();

		for (int j = 0; j < M; j++) { // 도로의 정보
			int S, E, T;
			cin >> S >> E >> T;
			edge[S].push_back({ E,T });
			edge[E].push_back({ S,T });
		}
		for (int j = 0; j < W; j++) { // 웜홀의 정보
			int S, E, T;
			cin >> S >> E >> T;
			edge[S].push_back({ E,-T });
		}	
		cout << (bellmanFord(N) ? "YES\n" : "NO\n");
	}
}
