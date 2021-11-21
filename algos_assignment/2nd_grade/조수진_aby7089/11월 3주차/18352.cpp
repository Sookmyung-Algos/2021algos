#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>

using namespace std;
vector <vector<pair<int,int>>> v;
int cnt = 0;
int n, m, k, x, a, b;

vector <int> dijk(int start) {
	vector<int> dist(n + 1, -1);
	priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	dist[start] = 0;
	pq.push({ dist[start],start });

	while (!pq.empty()) {
		int here = pq.top().second;
		int heredist = pq.top().first;
		pq.pop();
		if (heredist > dist[here])
			continue;
		for (int i = 0; i < v[here].size(); i++) {
			int there = v[here][i].first;
			int nextdist = heredist + v[here][i].second;

			if (dist[there] == -1 || dist[there] > nextdist) {
				dist[there] = nextdist;
				pq.push({ nextdist,there });
			}
		}
	}
	return dist;
}

int main() {
	cin >> n >> m >> k >> x;
	v.resize(n + 1);
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		v[a].push_back({ b, 1 });
	}
	vector <int> dist = dijk(x);
	for (int i = 1; i <= n; i++) {
		if (dist[i] == k) {
			++cnt;
			cout << i << "\n";
		}
	}
	if(cnt==0)
		cout << -1;
}
