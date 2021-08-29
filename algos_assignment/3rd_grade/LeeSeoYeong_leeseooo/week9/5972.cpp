#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<memory.h>
using namespace std;
#define INF 987654321
#define pii pair<int,int>
int n, m;
vector<pair<int, int>>v[50001];
int dist[50001];
int solve() {
	priority_queue<pii, vector<pii>, greater<pii>>pq;
	pq.push({ 1,0 });
	dist[1] = 0;
	while (!pq.empty()) {
		int cur = pq.top().first;
		int cost = pq.top().second;
		pq.pop();
		if (dist[cur] < cost)continue;
		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i].first;
			int ncost = v[cur][i].second;
			if (dist[next] > ncost + cost) {
				dist[next] = ncost + cost;
				pq.push({ next,dist[next] });
			}
		}
	}
	return dist[n];
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i <= 50000; i++)dist[i] = INF;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}
	cout << solve();
	return 0;
}
