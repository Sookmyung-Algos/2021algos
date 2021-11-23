#include <iostream>
#include <vector>
using namespace std;
#define MAX 501
#define INF 1e9

int n, m;
long long upper[MAX];
vector<pair<pair<int, int>, int>> adj;

void bellmanFord() {
	for (int i = 1; i <= n; i++) upper[i] = INF;
	upper[1] = 0;
	for (int i = 1; i <= n - 1; i++) {
		for (int j = 0; j < adj.size(); j++) {
			int from = adj[j].first.first;
			int to = adj[j].first.second;
			int cost = adj[j].second;

			if (upper[from] == INF) continue;
			if (upper[to] > upper[from] + cost){
				upper[to] = upper[from] + cost;
			}
		}
	}
	
	for (int i = 0; i < adj.size(); i++) {
		int from = adj[i].first.first;
		int to = adj[i].first.second;
		int cost = adj[i].second;

		if (upper[from] == INF) continue;
		if (upper[to] > upper[from] + cost) {
			cout << "-1\n";
			return;
		}
	}
	
	for (int i = 2; i <= n; i++) {
		if (upper[i] == INF) cout << "-1\n";
		else cout << upper[i] << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj.push_back({ {a, b}, c });
	}
	bellmanFord();
}
