#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<pair<int, int> > adj[510];
#define INF 987654321

void bellman(int n, int src) {
	vector<int> upper(n + 1, INF);
	upper[src] = 0;
	bool updated = false;
	for (int i = 0; i < n; i++) {
		updated = false;
		for (int j = 1; j <= n; j++)
			for (int r = 0; r < adj[j].size(); r++) {
				int there = adj[j][r].first;
				int cost = adj[j][r].second;
				if (upper[there] > upper[j] + cost) {
					upper[there] = upper[j] + cost;
					updated = true;
				}
			}
		if (!updated) {
			cout << "NO\n";
			break;
		}
	}
	if (updated)
		cout << "YES\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t, n, m, w;
	int a, b, c;

	cin >> t;

	while(t--) {
		cin >> n >> m >> w;
		for (int i = 1; i <= n; i++) {
			adj[i].clear();
		}
		//도로는 양방향
		for (int i = 0; i < m; i++) {
			cin >> a >> b >> c;
			adj[a].push_back({ b, c });
			adj[b].push_back({ a, c });
		}
		//웜홀은 역방향
		for (int i = 0; i < w; i++) {
			cin >> a >> b>> c;
			adj[a].push_back({ b, -c });
		}
		bellman(n, 1);
	}
	return 0;
}
