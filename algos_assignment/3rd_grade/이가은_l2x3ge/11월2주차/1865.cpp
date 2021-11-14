#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 987654321
using namespace std;

vector<pair<long long, pair<int, int>>> edge; // <cost, <from, to>>
long long dist[502];

bool Bellman_Ford(int n) {
	fill(dist, dist + n + 1, MAX);
	dist[1] = 0;

	for (int i = 0;i < n - 1;i++) {
		for (int j = 0;j < edge.size();j++) {
			int u = edge[j].second.first;
			int v = edge[j].second.second;
			long long cost = edge[j].first;

			//relax
			if (dist[v] > dist[u] + cost) {
				dist[v] = dist[u] + cost;
			}
		}
	}
	for (int j = 0;j < edge.size();j++) {
		int u = edge[j].second.first;
		int v = edge[j].second.second;
		long long cost = edge[j].first;

		if (dist[v] > dist[u] + cost) {
			dist[v] = -MAX;
			return false;
		}
	}
	return true;
}

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

	int T;
	cin >> T;
	while (T--) {
		int n, m, w;
		cin >> n >> m >> w;
		edge.clear();
		int s, e, t;
		for (int i = 0; i < m; i++) {
			cin >> s >> e >> t;
			edge.push_back({ t,{e,s } });
			edge.push_back({ t,{s,e } });
		}
		for (int i = 0; i < w; i++) {
			cin >> s >> e >> t;
			edge.push_back({ -t,{s,e } });
		}

		if (!Bellman_Ford(n)) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}
