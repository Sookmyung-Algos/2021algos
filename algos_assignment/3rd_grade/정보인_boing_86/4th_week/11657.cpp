#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321

using namespace std;

int n, m;
long long dist[501];
vector <pair<pair<int, int>, int>> E;
bool neg_c = false;

void bf() {
	dist[1] = 0;

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < E.size(); j++) {
			int from = E[j].first.first;
			int to = E[j].first.second;
			int cost = E[j].second;

			if (dist[from] == INF) {
				continue;
			}

			if (dist[to] > dist[from] + cost) {
				dist[to] = dist[from] + cost;
			}

		}
	}

	for (int i = 0; i < E.size(); i++) {//check
		int from = E[i].first.first;
		int to = E[i].first.second;
		int cost = E[i].second;

		if (dist[from] == INF) {
			continue;
		}
		if (dist[to] > dist[from] + cost) {
			neg_c = true;
		}
	}


}

int main() {
	int from, to, cost;

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		dist[i] = INF;
	}

	for (int i = 0; i < m; i++) {
		cin >> from >> to >> cost;
		E.push_back({ {from, to}, cost });
	}

	bf();

	for (int i = 2; i <= n; i++) {
		if (dist[i] == INF) {
			cout << -1 << endl;
			continue;
		}

		if (neg_c) {
			cout << -1 << endl;
			return 0;
		}

		cout << dist[i] << endl;
	}

}
