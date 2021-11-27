#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int>> v[1001];

int bfs(int s, int e) {
	queue<pair<int, int>> q;
	q.push({ s, 0 });

	int dist[1001] = { 0, };

	while (!q.empty()) {
		int cur = q.front().first;
		int cc = q.front().second;
		q.pop();

		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i].first;
			int nc = v[cur][i].second + cc;

			if (!dist[next] || dist[next] > nc) {
				dist[next] = nc;
				q.push({ next, nc });
			}
		}
	}

	return dist[e];
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m; cin >> n >> m;

	for (int i = 0, a, b, c; i < n - 1; i++) {
		cin >> a >> b >> c;
		v[a].push_back({ b, c });
		v[b].push_back({ a, c });
	}

	for (int i = 0, a, b; i < m; i++) {
		cin >> a >> b;
		cout << bfs(a, b) << '\n';
	}

	return 0;
}
