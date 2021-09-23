#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 2000000001 // 200000(n) * 10000(t)
using namespace std;

int n, m, k;
vector<pair<long long, int>> v[200001];
vector<int> s, ans;
priority_queue<pair<long long, int>> pq;
long long dist1[200001], dist2[200001];

void dijkstra() {
	fill(dist1, dist1 + n + 1, INF);
	for (int i = 0; i < s.size(); i++) {
		pq.push({ 0, s[i] });
		dist1[s[i]] = 1;
	}

	while (!pq.empty()) {
		long long cc = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (cc > dist1[cur]) continue;

		for (int i = 0; i < v[cur].size(); i++) {
			long long nc = cc + v[cur][i].first;
			int next = v[cur][i].second;

			if (nc < dist1[next]) {
				dist1[next] = nc;
				pq.push({ -nc, next });
			}
		}
	}

	fill(dist2, dist2 + n + 1, INF);

	pq.push({ 0, 1 });
	dist2[1] = 0;

	while (!pq.empty()) {
		long long cc = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (cc > dist2[cur]) continue;

		for (int i = 0; i < v[cur].size(); i++) {
			long long nc = cc + v[cur][i].first;
			int next = v[cur][i].second;

			if (nc < dist2[next]) {
				dist2[next] = nc;
				pq.push({ -nc, next });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m >> k;

	for (int i = 0, a, b, t; i < m; i++) {
		cin >> a >> b >> t;
		v[a].push_back({ t, b });
		v[b].push_back({ t, a });
	}
	
	for (int i = 0, x; i < k; i++) {
		cin >> x;
		s.push_back(x);
	}

	dijkstra();

	for (int i = 2; i <= n; i++) {
		if (dist1[i] > dist2[i]) ans.push_back(i);
	}

	if (ans.empty()) cout << "0\n";
	else {
		sort(ans.begin(), ans.end());
		for (int i : ans) cout << i << ' ';
		cout << '\n';
	}

	return 0;
}
