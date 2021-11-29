// G5_1240 노드사이의 거리

#include <iostream>
#include <vector>
#include <queue>
#define MAX 1001
using namespace std;

int N, M;
vector<pair<int,int>> adj[MAX];
bool visited[MAX];
int dist[MAX][MAX];

void dfs(int s, int e, int distance) {
	dist[s][e] = distance;
	for (int i = 0; i < adj[e].size(); i++) {
		int nnode = adj[e][i].first;
		int ncost = adj[e][i].second;
		if (!visited[nnode]) {
			visited[nnode] = 1;
			dfs(s, nnode, distance + ncost);
			visited[nnode] = 0;
		}

	}
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N-1; i++) {
		int a, b, c; cin >> a >> b >> c;
		adj[a].push_back(make_pair(b, c));
		adj[b].push_back(make_pair(a, c));
 	}

	for (int i = 1; i <= N; i++) {
		visited[i] = 1;
		dfs(i, i, 0); // 자기=0
		visited[i] = 0; 
	}

	for (int i = 0; i < M; i++) {
		int x, y; cin >> x >> y;
		cout << dist[x][y] << "\n";
	}
	return 0;
}
